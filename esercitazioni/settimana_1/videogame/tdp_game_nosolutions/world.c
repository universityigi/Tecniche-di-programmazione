#include "world.h"
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "surface.h"
#include "vehicle.h"
#include "image.h"
#include <sys/time.h>
#include "helpers.h"

void destroyWorld(World* w) {
  freeSurface(&w->ground);
  applyTextureToVehicle(&w->vehicle, 0);
}

int initWorld(World* w,
	       Image* surface_elevation,
	       Image* surface_texture,
	       Image* vehicle_texture,
	       float x_step, 
	       float y_step, 
	       float z_step) {

  Image* float_image = convertTo(surface_elevation, FLOATMONO);

  if (! float_image)
    return 0;

  buildSurfaceFromMatrix(&w->ground,
			 (float**) float_image->row_data, 
			 float_image->rows, 
			 float_image->cols,
			 .5, .5, 5);

  freeImage(float_image);

  vehicleInit(&w->vehicle, &w->ground);
  w->zoom = 1;
  w->dt = 1;
  w->camera_z = 1;
  gettimeofday(&w->last_update, 0);
  w->time_scale = 10;
  w->view_type=LOCAL_OUT_VEHICLE;
  w->window_width = w->window_height = 1;

  // initializes the GL context

  GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0};  // White diffuse light.
  GLfloat light_position[] = {100.0, 100.0, 100.0, 0.0};  //Infinite light location
  glEnable(GL_SMOOTH);
  glShadeModel(GL_SMOOTH);
  glPolygonMode( GL_FRONT, GL_FILL );
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  applyTextureToVehicle(&w->vehicle, vehicle_texture);
  applyTextureToSurface(&w->ground, surface_texture);
  w->n_flags=0;
  return 1;
}


void drawFlags(World* w) {
  for (int i = 0; i<w->n_flags; i++){
    float transform[16];
    float x = w->flags_x[i];
    float y = w->flags_y[i];
    int inside = getTransformOnSurface(transform, &w->ground,
    					x, y, 1, 0, 0);
    if (inside) {
      glPushMatrix();
      glMultMatrixf(transform);
      glColor3f(1,0,0);
      drawBox(1,1,1);
      glPopMatrix();
    }
  }
}

void displayWorld(World* w) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( /* field of view in degree */ 70.0,
		  /* aspect ratio */ (float)w->window_width/(float)w->window_height,
		  /* Z near */ 0.5, /* Z far */ 100.0);

  float camera_distance = 1./w->zoom;
  switch (w->view_type) {
  case LOCAL_OUT_VEHICLE:
    gluLookAt(-camera_distance,0,w->camera_z*camera_distance,
	      0,0,0,
	      0,0,1);
    glRotatef(-w->vehicle.theta*180.0/M_PI, 0, 0, 1);
    glTranslatef(-w->vehicle.x, -w->vehicle.y, -w->vehicle.z);
    break;
  case LOCAL_IN_VEHICLE:
    gluLookAt(-camera_distance,0,w->camera_z*camera_distance,
	      0,0,0,
	      0,0,1);
    glMultMatrixf(w->vehicle.world_to_camera);
    break;
  case GLOBAL:
    glLoadIdentity();
    gluLookAt(.5*w->ground.rows*w->ground.row_scale,
	      .5*w->ground.cols*w->ground.col_scale,
	      w->camera_z*10,
	      .5*w->ground.rows*w->ground.row_scale,
	      .5*w->ground.cols*w->ground.col_scale,
	      0,
	      1,0,0);
    break;
  }
  glMatrixMode(GL_MODELVIEW);
  drawSurface(&w->ground);
  drawVehicle(&w->vehicle);
  drawFlags(w);
  glutSwapBuffers();
}

void updateWorld(World* w, float tf, float rf) {
  struct timeval current_time;
  gettimeofday(&current_time, 0);
  
  struct timeval dt;
  timersub(&current_time, &w->last_update, &dt);
  float delta = dt.tv_sec+1e-6*dt.tv_usec;
  if (! vehicleUpdate(&w->vehicle, tf, rf, delta*w->time_scale)){
    vehicleReset(&w->vehicle);
  }
 
  
  int idx = nearestElement(w->flags_x, w->flags_y, w->n_flags, w->vehicle.x, w->vehicle.y, 5);

  if (idx!=-1){
    w->flags_x = removeElementAt(w->flags_x, idx, w->n_flags);
    w->flags_y = removeElementAt(w->flags_y, idx, w->n_flags);
    w->n_flags--;
  }
  w->last_update = current_time;
}

void reshapeWorldViewport(World* w, int width, int height){
  w->window_width  = width;
  w->window_height = height;
  glViewport(0, 0, width, height);
}


void setFlagsInWorld(World* w, float* x, float*y, int n_flags) {
  w->flags_x=x;
  w->flags_y=y;
  w->n_flags=n_flags;
}
