#include "../include/enemy.h"

enemy::enemy(const loadParams *lP) : SDLGameObject(lP) {

}

void enemy::draw () {

  SDLGameObject::draw();
}

void enemy::update() {

  memPos.setX(memPos.getX() + 1);
  memPos.setY(memPos.getY() + 1);

  //memCurFrame = int(((SDL_GetTicks() / 100) % 6 ));
}

void enemy::clean() {
 
  ;
}