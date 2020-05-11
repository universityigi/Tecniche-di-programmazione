#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "vec3.h"
#include "image.h"

//! 3d surface, represented as a matrix of 3d points with normals
typedef struct Surface{
  //! linear array of points
  Vec3 *points;

  //! linear array of normals
  Vec3 *normals;

  //! points as a matrix
  Vec3 **point_rows;

  //! normals as a matrix
  Vec3 **normal_rows;

  //! number of rows and of columns
  int rows, cols;
  
  //! step between adjacent points
  float row_scale, col_scale;

  //! number of points =(rows*cols)
  int n_points;

  int gl_list;
  int gl_texture;
} Surface;

//alloates a surface that holds a matrix of rows times cols points
// s should point to a struct Surface
void allocateSurface(Surface* s, int rows, int cols, float row_scale, float col_scale);

//frees the memory of a surface
// s should point to a struct Surface
void freeSurface(Surface* s);

//!constructs a surface out of a grid representation of a surface z=f(rows,cols)
//!and computes the normals
//! @param s: a pointer to a valid surface
//! @param m: a matrix of  rows by cols z elements
//! @param x_scale: the step of each row
//! @param x_scale: the step of each col
//! @param z_scale: the value to multiply by m[r,c] to get the elevation of the point

void buildSurfaceFromMatrix(Surface* s, 
			    float** m, int rows, int cols,
			    float row_scale, float col_scale, float z_scale);

//! applies the image img to the surface as texture.
//! the image is stretched to cover all surface
//! if a texture was already present it is destroyed
void applyTextureToSurface(Surface* s, Image* img);

//! draws a surface
//! @param s: the surface to draw
void drawSurface(Surface* s) ;

int getTransformOnSurface(float transform[16], Surface* s,
			  float x, float y, float z, float alpha, int inverse);

#endif
