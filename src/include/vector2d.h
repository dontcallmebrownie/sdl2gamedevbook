#ifndef VECTOR2D_H
#define VECTOR2D_H


#include <math.h>


class vector2d {

public:

  vector2d(float x, float y) : memX(x), memY(y) {}
  vector2d() {}
  float length() {

  return sqrt(memX * memX + memY * memY);
  }

  float getX() {return memX;}
  float getY() {return memY;}

  void setX(int x) {memX = x;}
  void setY(int y) {memY = y;}

  // Overload mathematic operations
  vector2d operator+(const vector2d& v2) const {

  return vector2d(memX + v2.memX, memY + v2.memY);
  }

  friend vector2d& operator+=(vector2d& v1, const vector2d& v2) {

    v1.memX += v2.memX;
    v1.memY += v2.memY;

  return v1;
  }

  vector2d operator-(const vector2d& v2) const {

  return vector2d(memX - v2.memX, memY - v2.memY);
  }

  friend vector2d& operator-=(vector2d& v1, const vector2d& v2) {

    v1.memX -= v2.memX;
    v1.memY -= v2.memY;

  return v1;
  }

  vector2d operator*(float scalar) {

  return vector2d(memX * scalar, memY * scalar);
  }

  vector2d& operator*=(float scalar) {

    memX *= scalar;
    memY *= scalar;

  return *this;
  }

  vector2d operator/(float scalar) {

  return vector2d(memX / scalar, memY / scalar);
  }

  vector2d& operator/=(float scalar) {

    memX /= scalar;
    memY /= scalar;

  return *this;
  }

  void normalize() {

    float l = length();
    
    if (l > 0) {

      (*this) *= (1 / l);
    }
  }

private:

  float memX;
  float memY;
};


#endif