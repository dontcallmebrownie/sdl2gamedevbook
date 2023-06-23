#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"

class Game {

public:
 // Game();
 // ~Game();
  
  bool init(const char* t, int h, int w, int f);
  void render();
  void load();
  void update();
  void eventsHandler();
  void clean();

  bool getRunning() {return running;}

private:

  bool running;

  SDL_Window *win;
  SDL_Renderer *screen;



};


#endif // GAME_H