#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <iostream>
//#include <fstream>
#include <string>

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>


class gameObject {

public:

  virtual void load(int x, int y, int w, int h, std::string id);
  virtual void draw(SDL_Renderer *screen); // {std::cout << "gameObject.draw() Called!\n";}
  virtual void update(); // {std::cout << "gameObject.update() Called!\n";}
  virtual void clean(); // {std::cout << "gameObject.clean() Called!\n";}

protected:

  std::string memId;
  
  int memCurFrame;
  int memCurRow;

  int memX;
  int memY;
  int memW;
  int memH;

};

#endif