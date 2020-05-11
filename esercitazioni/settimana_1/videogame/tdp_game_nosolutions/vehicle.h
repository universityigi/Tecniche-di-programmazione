#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include "surface.h"
#include "image.h"

typedef struct Vehicle {
  Surface* ground;
  float x,y, z, theta; //orientation of the vehicle, on the surface
  float prev_x, prev_y, prev_z, prev_theta; //orientation of the vehicle, on the surface
  float translational_velocity;
  float rotational_velocity;
  float translational_viscosity;
  float rotational_viscosity;
  float world_to_camera[16];
  float camera_to_world[16];
  float mass, angular_mass;
  int gl_texture;
  float rotational_force, max_rotational_force, min_rotational_force;
  float translational_force, max_translational_force, min_translational_force;

} Vehicle;

void vehicleInit(Vehicle* v, Surface* s);

void vehicleReset(Vehicle* v);

int vehicleUpdate(Vehicle* v, float tf, float rf, float dt);
 
void drawVehicle(Vehicle* v);

void applyTextureToVehicle(Vehicle* v, Image* img);

void drawBox(float l, float w, float h);
#endif
