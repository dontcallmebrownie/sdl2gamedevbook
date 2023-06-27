#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <string>
#include <vector>

#include "./texman.h"
#include "./gameobject.h"
#include "./player.h"
#include "./enemy.h"

class game {

public:
  
  static game *Instance() {

    if(inst == 0) {

      inst = new game();
    return inst;
    }
  return inst;
  }

  ~game() {}
  
  bool init(const char* t, int h, int w, bool f);
  void render();
  void update();
  void eventsHandler();
  void clean();

  bool getRunning() {return running;}
  SDL_Renderer *getRenderer() const {return screen;}

  gameObject *go;
  gameObject *p;
  gameObject *e;

  std::vector<gameObject*> memGameObjects; 

private:

  game() {}

  static game *inst;

  SDL_Window *win;
  SDL_Renderer *screen;

  bool running;
};

  typedef game theGame;

#endif // GAME_H