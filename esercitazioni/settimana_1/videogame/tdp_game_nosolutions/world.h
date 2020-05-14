#ifndef _WORLD_H_
#define _WORLD_H_
#include <sys/time.h>

#include "image.h"
#include "surface.h"
#include "vehicle.h"

typedef enum WorldViewType {LOCAL_IN_VEHICLE, LOCAL_OUT_VEHICLE, GLOBAL} WorldViewType;

typedef struct World {
  Surface ground;
  Vehicle vehicle;
  float dt;
  float zoom;
  float camera_z;
  int window_width, window_height;
  struct timeval last_update;
  float time_scale;
  WorldViewType view_type;
  float* flags_x;
  float* flags_y;
  int n_flags;
} World;

int initWorld(World* w,
	       Image* surface_elevation,
	       Image* surface_texture,
	       Image* vehicle_texture,
	       float x_step, 
	       float y_step, 
	       float z_step);

void destroyWorld(World* w);
		    
void reshapeWorldViewport(World* w, int width, int height);

void displayWorld(World* w);

void updateWorld(World* w, float tf, float rf);

void setFlagsInWorld(World* w, float* x, float*y, int n_flags);

#endif

