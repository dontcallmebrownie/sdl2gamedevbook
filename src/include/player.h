#ifndef PLAYER_H
#define PLAYER_H

/*
#include <iostream>
//#include <fstream>
#include <string>

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
*/

#include "gameobject.h"

class player: public gameObject {

public:

  void load(int x, int y, int w, int h, std::string id);
  void draw(SDL_Renderer *screen);
  void update();
  void clean();
};


#endif