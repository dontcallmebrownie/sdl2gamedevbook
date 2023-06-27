#ifndef PLAYER_H
#define PLAYER_H


#include "sdlgameobject.h"

class player: public SDLGameObject {

public:

  player(const loadParams *lP);

  virtual void draw();
  virtual void update();
  virtual void clean();
};


#endif