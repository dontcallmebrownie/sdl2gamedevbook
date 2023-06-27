#ifndef ENEMY_H
#define ENEMY_H


#include "sdlgameobject.h"

class enemy: public SDLGameObject {

public:
  
  enemy(const loadParams *lP);

  virtual void draw();
  virtual void update();
  virtual void clean();
};
























#endif