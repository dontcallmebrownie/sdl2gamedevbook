#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <string>
#include <vector>

#include "./texman.h"
#include "./gameobject.h"
#include "./player.h"
#include "./enemy.h"
#include "inputhandler.h"
#include "gamestatemachine.h"
#include "menustate.h"
#include "playstate.h"


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
  void quit() { running = false;}
  SDL_Renderer *getRenderer() const {return screen;}

  gameStateMachine* getStateMachine(){return memGSM;}
 

  std::vector<gameObject*> memGameObjects; 

private:

  game() {}

  static game *inst;

  SDL_Window *win;
  SDL_Renderer *screen;
  gameStateMachine *memGSM;

  bool running;
};

  typedef game theGame;

#endif // GAME_H