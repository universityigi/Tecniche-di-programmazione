#include "vehicle.h"
#include <GL/gl.h>
#include <math.h>

void drawBox(float l, float w, float h)
{
  GLfloat sx = l*0.5f;
  GLfloat sy = w*0.5f;
  GLfloat sz = h*0.5f;

  glBegin(GL_QUADS);
  // bottom
  glNormal3f( 0.0f, 0.0f,-1.0f);
  glVertex3f(-sx, -sy, -sz);
  glVertex3f(-sx, sy, -sz);
  glVertex3f(sx, sy, -sz);
  glVertex3f(sx, -sy, -sz);

  // top
  glNormal3f( 0.0f, 0.0f,1.0f);
  glTexCoord2f(0,0);
  glVertex3f(-sx, -sy, sz);
  glTexCoord2f(0,1);
  glVertex3f(-sx, sy, sz);
  glTexCoord2f(1,1);
  glVertex3f(sx, sy, sz);
  glTexCoord2f(1,0);
  glVertex3f(sx, -sy, sz);
  // back
  glNormal3f(-1.0f, 0.0f, 0.0f);
  glVertex3f(-sx, -sy, -sz);
  glVertex3f(-sx, sy, -sz);
  glVertex3f(-sx, sy, sz);
  glVertex3f(-sx, -sy, sz);
  // front
  glNormal3f( 1.0f, 0.0f, 0.0f);
  glVertex3f(sx, -sy, -sz);
  glVertex3f(sx, sy, -sz);
  glVertex3f(sx, sy, sz);
  glVertex3f(sx, -sy, sz);
  // left
  glNormal3f( 0.0f, -1.0f, 0.0f);
  glVertex3f(-sx, -sy, -sz);
  glVertex3f(sx, -sy, -sz);
  glVertex3f(sx, -sy, sz);
  glVertex3f(-sx, -sy, sz);
  //right
  glNormal3f( 0.0f, 1.0f, 0.0f);
  glVertex3f(-sx, sy, -sz);
  glVertex3f(sx, sy, -sz);
  glVertex3f(sx, sy, sz);
  glVertex3f(-sx, sy, sz);
  glEnd();
}

int vehicleUpdate(Vehicle* v, float tf, float rf, float dt){
  if (tf > v->max_translational_force)
    tf = v->max_translational_force;
  if (tf < -v->max_translational_force)
    tf = -v->max_translational_force;

  if (rf > v->max_rotational_force)
    rf = v->max_rotational_force;
  if (rf < -v->max_rotational_force)
    rf = -v->max_rotational_force;
  

  // retrieve the position of the vehicle
  if(! getTransformOnSurface(v->camera_to_world, v->ground, v->x, v->y, 0, v->theta, 0)) {
    v->translational_velocity = 0;
    v->rotational_velocity = 0;
    return 0;
  }
  // compute the new pose of the vehicle, based on the velocities
  // vehicle moves only along the x axis!

  float nx = v->camera_to_world[12] + v->camera_to_world[0] * v->translational_velocity * dt;
  float ny = v->camera_to_world[13] + v->camera_to_world[1] * v->translational_velocity * dt;

  if(! getTransformOnSurface(v->camera_to_world, v->ground, nx, ny, 0, v->theta, 0)) {
    return 0;
  }
  v->x=v->camera_to_world[12];
  v->y=v->camera_to_world[13];
  v->z=v->camera_to_world[14];
  v->theta += v->rotational_velocity * dt;

  if(! getTransformOnSurface(v->camera_to_world, v->ground, nx, ny, 0, v->theta, 0)){
    return 0;
  }

  // compute the accelerations
  float global_tf=(-9.8 * v->camera_to_world[2] + tf);
  if ( fabs(global_tf)<v->min_translational_force)
    global_tf = 0;
  v->translational_velocity += global_tf * dt;

  if ( fabs(rf)<v->min_rotational_force)
    rf = 0;
  v->rotational_velocity += rf * dt;
  v->translational_velocity *= v->translational_viscosity;
  v->rotational_velocity *= v->rotational_viscosity;
  getTransformOnSurface(v->world_to_camera, v->ground, nx, ny, 0, v->theta, 1);
  return 1;
}


void vehicleInit(Vehicle* v, Surface* s){
  v->gl_texture = -1;
  v->ground = s;
  v->max_rotational_force=0.5;
  v->max_translational_force=10;
  v->min_rotational_force=0.05;
  v->min_translational_force=0.05;
  vehicleReset(v);
}


void vehicleReset(Vehicle* v){
  v->rotational_force=0;
  v->translational_force=0;
  v->x = v->ground->rows/2 * v->ground->row_scale;
  v->y = v->ground->cols/2 * v->ground->col_scale;
  v->theta = 0;
  v->translational_viscosity = 0.5;
  v->rotational_viscosity = 0.5;
  if(! getTransformOnSurface(v->camera_to_world, v->ground, v->x, v->y, 0, v->theta, 0))
    return;
}


void drawVehicle(Vehicle* v){
  if (v->gl_texture>-1){
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, v->gl_texture); 
  }

  glPushMatrix();
  glMultMatrixf(v->camera_to_world);
  glTranslatef(0,0,0.3);
  drawBox(0.5,0.5,0.25);
  glPopMatrix();
  
  if (v->gl_texture>-1)
    glDisable(GL_TEXTURE_2D);

}


void applyTextureToVehicle(Vehicle* v, Image* img) {
  if (v->gl_texture>-1)
    glDeleteTextures(1, (unsigned int*) &v->gl_texture);
  v->gl_texture = -1;
  if (img)
    v->gl_texture=makeTextureFromImage(img);
}
