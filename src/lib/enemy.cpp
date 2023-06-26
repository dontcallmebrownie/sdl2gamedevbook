#include "../include/enemy.h"

void enemy::load(int x, int y, int w, int h, std::string id) {

  gameObject::load(x, y, w, h, id);
}

void enemy::draw (SDL_Renderer *screen) {

  gameObject::draw(screen);
}

void enemy::update() {

  memY += 1;
  memX += 1;
  memCurFrame = int(((SDL_GetTicks() / 100) % 6 ));
}

void enemy::clean() {
 
  ;
}