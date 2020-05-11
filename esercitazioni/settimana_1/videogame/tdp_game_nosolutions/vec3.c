#include "vec3.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

void v3compose(Vec3* dest, const Vec3* a, const Vec3* b, float alpha_a, float alpha_b){
  dest->values[0]=a->values[0]*alpha_a+b->values[0]*alpha_b;
  dest->values[1]=a->values[1]*alpha_a+b->values[1]*alpha_b;
  dest->values[2]=a->values[2]*alpha_a+b->values[2]*alpha_b;
}

float v3dot(const Vec3* a, const Vec3* b){
  return a->values[0]*b->values[0]+a->values[1]*b->values[1]+a->values[2]*b->values[2];
}

void v3cross(Vec3* dest, const Vec3* a, const Vec3* b){
  dest->values[0]=a->values[1]*b->values[2]-a->values[2]*b->values[1];
  dest->values[1]=a->values[2]*b->values[0]-a->values[0]*b->values[2];
  dest->values[2]=a->values[0]*b->values[1]-a->values[1]*b->values[0];
}

void v3scale(Vec3* dest, float s){
  dest->values[0]*=s;
  dest->values[1]*=s;
  dest->values[2]*=s;
}


void v3normalize(Vec3* dest){
  float n2=v3dot(dest, dest);
  n2=1./sqrt(n2);
  v3scale(dest, n2);
}

void mat4mult(float dest[], float a[], float b[]){
  memset(dest, 0, 16*sizeof(float));
  for(int r=0; r<4; r++)
    for (int c=0; c<4; c++){
      float* mrc=dest+(c*4+r);
      for (int i=0; i<4; i++){
	(*mrc) +=  a[i*4+r] * b[4*c+i];
      }
    }

  /* printf("A\n"); */
  /* for(int r=0; r<4; r++) { */
  /*   for (int c=0; c<4; c++){ */
  /*     float* mrc=a+(c*4+r); */
  /*     printf ("%f ", *mrc); */
  /*   } */
  /*   printf("\n"); */
  /* } */

  /* printf("B\n"); */
  /* for(int r=0; r<4; r++) { */
  /*   for (int c=0; c<4; c++){ */
  /*     float* mrc=b+(c*4+r); */
  /*     printf ("%f ", *mrc); */
  /*   } */
  /*   printf("\n"); */
  /* } */


  /* printf("C\n"); */
  /* for(int r=0; r<4; r++) { */
  /*   for (int c=0; c<4; c++){ */
  /*     float* mrc=dest+(c*4+r); */
  /*     printf ("%f ", *mrc); */
  /*   } */
  /*   printf("\n"); */
  /* } */

}

void mat4rotationX(float dest[], float alpha){
  float s = sin(alpha), c=cos(alpha);
  memset(dest, 0, 16*sizeof(float));
  dest[0]=c;
  dest[1]=s;
  dest[4]=-s;
  dest[5]=c;
  dest[10]=dest[15]=1;
}
