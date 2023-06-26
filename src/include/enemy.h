#ifndef ENEMY_H
#define ENEMY_H


#include "gameobject.h"

class enemy: public gameObject {

public:
  
  void load(int x, int y, int w, int h, std::string id);
  void draw(SDL_Renderer *screen);
  void update();
  void clean();
};
























#endif