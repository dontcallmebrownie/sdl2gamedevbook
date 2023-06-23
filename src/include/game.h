#ifndef GAME_H
#define GAME_H


#include <iostream>
//#include <fstream>
#include <string>

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "./texman.h"

class Game {

public:
  
  //Game();
  //~Game();
  
  bool init(const char* t, int h, int w, bool f);
  void render();
  void update();
  void eventsHandler();
  void clean();

  bool getRunning() {return running;}

  int curFrame;

private:

  SDL_Window *win;
  SDL_Renderer *screen;

  bool running;
};


#endif // GAME_H