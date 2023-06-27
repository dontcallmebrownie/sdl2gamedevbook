#ifndef LOADPARAMS_H
#define LOADPARAMS_H


#include <iostream>
#include <string>

class loadParams {

public:

  loadParams(int x, int y, int w, int h, std::string id) : memX(x), memY(y), memW(w), memH(h), memId(id) {

  }

  int getX() const {return memX;}
  int getY() const {return memY;}
  int getW() const {return memW;}
  int getH() const {return memH;}

  std::string getId() const {return memId;}

private:

  int memX;
  int memY;
  int memW;
  int memH;

  std::string memId;
};


#endif