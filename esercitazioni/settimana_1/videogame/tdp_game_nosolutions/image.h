#ifndef _IMAGE_H_
#define _IMAGE_H_

typedef enum PixelType {
  RGB8=0x0, 
  MONO8=0x1, 
  RGB16=0x2,
  MONO16=0x3, 
  FLOATMONO=0x4, 
  FLOATRGB=0x5
} PixelType;

typedef struct Image {
  int rows, cols, channels;
  unsigned char* data;
  unsigned char ** row_data;
  PixelType type;
} Image;

Image* createImage(int rows, int cols, PixelType type);

Image* loadImage(const char* filename);

Image* convertTo(Image* src, PixelType type);

void freeImage(Image* img);

int makeTextureFromImage(Image* src);

#endif
