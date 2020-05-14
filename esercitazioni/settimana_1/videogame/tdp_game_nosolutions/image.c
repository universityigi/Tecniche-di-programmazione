#include "image.h"
#include <stdio.h>
#include <GL/gl.h>
#include <string.h>
#include <stdlib.h>

void freeImage(Image* img) {
  free(img->data);
  free(img->row_data);
  free(img);
}

Image* createImage(int rows, int cols, PixelType type){
  int bpp=1;
  int channels = 1;
  switch(type) {
  case MONO8: 
    bpp=1; 
    channels = 1; 
    break;
  case MONO16: 
    bpp=2; 
    channels = 1; 
    break;
  case RGB8: 
    bpp=3; 
    channels = 3; 
    break;
  case RGB16: 
    bpp=6; 
    channels = 3; 
    break;
  case FLOATMONO: 
    bpp=sizeof(float); 
    channels = 1; 
    break;
  case FLOATRGB: 
    bpp=sizeof(float)*3; 
    channels = 3; 
    break;
  }

  Image* img = malloc(sizeof(Image));
  img->rows = rows;
  img->cols = cols;					
  img->channels = channels;
  img->data = (unsigned char*) malloc(rows*cols*bpp);
  img->row_data = (unsigned char**) malloc(sizeof(unsigned char*)*rows);
  unsigned char* base_data = img->data;
  for (size_t i=0; i<rows; i++){
    img->row_data[i]=base_data;
    base_data += cols*bpp;
  }
  return img;
}

Image* loadImage(const char* filename) {
  FILE* f=fopen(filename, "r");
  if (!f)
    return 0;
  char magic_number[100];
  int rows, cols;
  int bpp=1;
  char  line [1024];
  line[0]='#';
  if (!fgets(line, 100, f))
    return 0;
  sscanf(line, "%s", magic_number);
  do{
    if (!fgets(line, 1000, f))
      return 0;
    printf("read");
  } while(line[0]=='#');

  sscanf(line, "%d %d\n", &cols, &rows);
  printf("rows:%d, cols: %d\n", rows, cols);
  printf("magic number: [%s]\n", magic_number);

  int maxval;
  if (!fgets(line, 1024, f))
    return 0;
  sscanf(line, "%d\n", &maxval);
  
  PixelType type=MONO8;
  if (! strcmp("P5", magic_number)) {
    if (maxval>255) {
      bpp=2;
      type = MONO16;
    }
  } else if (! strcmp("P6", magic_number)){
    if (maxval>255) {
      bpp=6;
      type = RGB16;
    } else {
      type = RGB8;
      bpp=3;
    }
  } else
    return 0;
  
  
  Image* img = createImage(rows, cols, type);
  int blocks_read = fread(img->data, bpp, rows*cols, f);
  if (blocks_read != rows*cols){
    printf("error in loading raster part of image, read %d bytes, expected %d bytes\n",
	   blocks_read, rows*cols);
  }
  fclose(f);
  img->type=type;
  return img;
}



Image* convertTo(Image* src, PixelType type){
  
  float scale;
  if (src->type == MONO8 && type == FLOATMONO) {
    scale=1./255;
  } else if (src->type == MONO16 && type == FLOATMONO){
    scale=1./6000;
  } else if (src->type == RGB8 && type == FLOATRGB){
    scale=1./255;
  } else if (src->type == RGB16 && type == FLOATRGB){
    scale=1./65535;
  } else return 0;
  
  Image* img=createImage(src->rows, src->cols, type);
  
  for (int r=0; r<src->rows; r++){
    float* destptr=(float*) img->row_data[r];
    unsigned char* srcptr = src->row_data[r];
    for (int c=0; c<src->cols; c++){
      for (int i=0; i<src->channels; i++){
	if (src->type==MONO16 || src->type==RGB16){
	  unsigned int c_up = *srcptr;
	  srcptr++;
	  unsigned int  c_low = *srcptr;
	  srcptr++;
	  int v=(c_up<<8) + c_low;
	  *destptr=scale * v;
	  destptr++;
	} else {
	  *destptr=scale * (*srcptr);
	  srcptr++;
	  destptr++;
	}
      }
    }
  }
  return img;
}


int makeTextureFromImage(Image* src) {
  if (src->type!=RGB8)
    return -1;
   unsigned int surface_texture;
   printf("loading texture in system\n");
   glGenTextures(1, &surface_texture);
   glBindTexture(GL_TEXTURE_2D, surface_texture);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, src->rows, src->cols, 0,
		GL_RGB, GL_UNSIGNED_BYTE, src->data);
   return surface_texture;
}
