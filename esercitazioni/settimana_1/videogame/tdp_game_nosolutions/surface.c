#include "surface.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


void allocateSurface(Surface* s, int rows, int cols, float row_scale, float col_scale){
  s->rows = rows;
  s->cols = cols;
  s->row_scale = row_scale;
  s->col_scale = col_scale;
  s->n_points = rows*cols;
  s->points = (Vec3*) malloc (sizeof(Vec3)*s->n_points);
  s->normals = (Vec3*) malloc (sizeof(Vec3)*s->n_points);
  memset(s->points, 0, (sizeof(Vec3)*s->n_points));
  memset(s->normals, 0, (sizeof(Vec3)*s->n_points));
  s->point_rows = (Vec3**) malloc  (sizeof (Vec3*)*rows);
  s->normal_rows = (Vec3**) malloc  (sizeof (Vec3*)*rows);
  for (int i = 0; i<rows; i++){
    s->point_rows[i] = s->points + (i*cols);
    s->normal_rows[i] = s->normals + (i*cols);
  }
  s->gl_list=-1;
  s->gl_texture=-1;
}

void freeSurface(Surface* s) {
  if (s->points){
    free(s->points);
    free(s->point_rows);
  }
  if (s->normals) {
    free(s->normals);
    free(s->normal_rows);
  }
  s->points = 0;
  s->normals = 0;
  s->n_points = 0;
  s->rows = 0;
  s->cols = 0;
  s->gl_texture = -1;
  if (s->gl_list>-1)
    glDeleteLists(s->gl_list, 1);
  s->gl_list=-1;
  if (s->gl_texture>-1)
    glDeleteTextures(1, (unsigned int*)&s->gl_texture);
}

void buildSurfaceFromMatrix(Surface* s, 
			    float** m, int rows, int cols,
			    float row_scale, float col_scale, float z_scale) {
  allocateSurface(s,rows,cols, row_scale, col_scale);
  // compute the points
  for (int r=0; r<rows; r++) {
    Vec3* points_row_ptr = s->point_rows[r];
    for (int c=0; c<cols; c++) {
      points_row_ptr->values[0]=row_scale*r;
      points_row_ptr->values[1]=col_scale*c;
      points_row_ptr->values[2]=z_scale*m[r][c];
      points_row_ptr++;
    }
  }
  for (int r=1; r<rows-1; r++) {
    Vec3* normals_row_ptr = s->normal_rows[r];
    Vec3* points_row_ptr = s->point_rows[r];
    Vec3* points_row_prev = s->point_rows[r-1];
    Vec3* points_row_next = s->point_rows[r+1];
    for (int c=1; c<cols-1; c++) {
      Vec3 delta_px, delta_py;
      v3compose(&delta_px, points_row_next, points_row_prev, 1, -1);
      v3compose(&delta_py, points_row_ptr+1, points_row_ptr-1, 1, -1);
      v3cross(normals_row_ptr, &delta_px, &delta_py);
      v3normalize(normals_row_ptr);
      points_row_ptr++;
      points_row_next++;
      points_row_prev++;
      normals_row_ptr++;
    }
  }
}

void applyTextureToSurface(Surface* s, Image* img) {
  if (s->gl_list>-1)
    glDeleteLists(s->gl_list, 1);
  s->gl_list = -1;
  if (s->gl_texture>-1)
    glDeleteTextures(1, (unsigned int*) &s->gl_texture);
  s->gl_texture = -1;
  if (img)
    s->gl_texture=makeTextureFromImage(img);
}

void drawSurface(Surface* s) {
  if (s->gl_list > -1) {
    glCallList(s->gl_list);
    return;
  }
  
  s->gl_list = glGenLists(1);
  glNewList(s->gl_list, GL_COMPILE_AND_EXECUTE);
  if (s->gl_texture>-1){
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, s->gl_texture); 
  }
    
  for (int r=0; r<s->rows-1; r++) {
    Vec3* normals_row_ptr = s->normal_rows[r];
    Vec3* normals_row_next = s->normal_rows[r+1];
    Vec3* points_row_ptr = s->point_rows[r];
    Vec3* points_row_next = s->point_rows[r+1];
    glBegin(GL_TRIANGLE_STRIP);
    for (int c=0; c<s->cols-1; c++){
      glNormal3fv(normals_row_ptr->values);
      glTexCoord2f((float) c/s->cols, (float)r/s->rows);
      glVertex3fv(points_row_ptr->values);
      
      glNormal3fv(normals_row_next->values);
      glTexCoord2f( (float) c/s->cols, (float)(r+1)/s->rows);
      glVertex3fv(points_row_next->values);
      
      normals_row_ptr++;
      points_row_ptr++;
      normals_row_next++;
      points_row_next++;
      glNormal3fv(normals_row_ptr->values);
      glTexCoord2f((float) (c+1)/s->cols, (float)r/s->rows);
      glVertex3fv(points_row_ptr->values);
      glNormal3fv(normals_row_next->values);
      glTexCoord2f((float) (c+1)/s->cols, (float)(r+1)/s->rows);
      glVertex3fv(points_row_next->values);
    }
    glEnd();
  }

  if (s->gl_texture>-1){
    glDisable(GL_TEXTURE_2D);
  }
  glEndList();

}

int getTransformOnSurface(float transform[16], Surface* s,
			  float x, float y, float z, float alpha, int inverse) {

  memset(transform, 0, 16*sizeof(float));

  // retrieve the cell of the matrix corresponding to the float coordinates x and y
  int r = floor(x/s->row_scale);
  int c = floor(y/s->col_scale);
  if (r<1 || r>s->rows-2 || c<1 || c>s->cols-2)
    return 0;
  
  // coefficients for interpolation
  float dx = (x-r*s->row_scale)/s->row_scale;
  float dy = (y-c*s->col_scale)/s->col_scale;
  
  // retrieve the neighbors for interpolation
  Vec3 p=s->point_rows[r][c];
  Vec3 n=s->normal_rows[r][c];

  
  Vec3 px=s->point_rows[r+1][c];
  Vec3 nx=s->normal_rows[r+1][c];

  Vec3 py=s->point_rows[r][c+1];
  Vec3 ny=s->normal_rows[r][c+1];

  Vec3 dpx;
  v3compose(&dpx, &px, &p, dx, -dx);
  Vec3 dpy;
  v3compose(&dpy, &py, &p, dy, -dy);
  Vec3 dp;
  v3compose(&dp, &dpx, &dpy, 1, 1);
  v3compose(&p, &p, &dp, 1, 1);

  Vec3 dnx;
  v3compose(&dnx, &nx, &n, dx, -dx);
  Vec3 dny;
  v3compose(&dny, &ny, &n, dy, -dy);
  Vec3 dn;
  v3compose(&dn, &dnx, &dny, 1, 1);
  v3compose(&n, &n, &dn, 1, 1);
  v3normalize(&n);
  

  // compute the y versor as the cross product between the normal and a verctor oriented
  // along the alpha angle lying on the xy plane
  Vec3 rx, ry;
  rx.values[0]=cos(alpha);
  rx.values[1]=sin(alpha);
  rx.values[2]=0;
  v3cross(&ry, &n, &rx);
  v3normalize(&ry);

  // compute the x versor as the cross product between ry and the normal
  v3cross(&rx, &ry, &n);
  v3normalize(&rx);

  //p.values[0]=x;
  //p.values[1]=y;

  Vec3 t;
  v3compose(&t, &p, &n, 1, z);
 
  float* A=transform;
  if (inverse) {
    A[0]=rx.values[0]; A[4]=rx.values[1]; A[8]=rx.values[2]; A[12]=-v3dot(&rx,&t);
    A[1]=ry.values[0]; A[5]=ry.values[1]; A[9]=ry.values[2]; A[13]=-v3dot(&ry,&t);
    A[2]=n.values[0];  A[6]=n.values[1];  A[10]=n.values[2]; A[14]=-v3dot(&n, &t);
  } else {
    A[0]=rx.values[0]; A[4]=ry.values[0]; A[8]=n.values[0]; A[12]=t.values[0];
    A[1]=rx.values[1]; A[5]=ry.values[1]; A[9]=n.values[1]; A[13]=t.values[1];
    A[2]=rx.values[2]; A[6]=ry.values[2]; A[10]=n.values[2]; A[14]=t.values[2];
  }
  A[15]=1;
  return 1;
}

