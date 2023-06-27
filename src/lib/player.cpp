#include "../include/player.h"

player::player(const loadParams *lP) : SDLGameObject(lP) {

}

void player::draw () {

  SDLGameObject::draw();
}

void player::update(){

  memX -= 1;
  memCurFrame = int(((SDL_GetTicks() / 100) % 6));
}

void player::clean() {
 
  ;
}