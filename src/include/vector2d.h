#ifndef VECTOR2D_H
#define VECTOR2D_H


#include <math.h>


class vector2d {

public:

  vector2d(float x, float y) : memX(x), memY(y) {}
  float lenght() {

  return sqrt(memX * memX + memY * memY);
  }

  float getX() {return memX;}
  float getY() {return memY;}

  void setX(float x) {memX = x;}
  void setY(float y) {memY = y;}

private:

  float memX;
  float memY;
};




#endif