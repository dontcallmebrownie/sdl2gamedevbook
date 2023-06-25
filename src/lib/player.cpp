#include "../include/player.h"

void player::load(int x, int y, int w, int h, std::string id) {

  gameObject::load(x, y, w, h, id);
}

void player::draw (SDL_Renderer *screen) {

  gameObject::draw(screen);
}

void player::update(){

  gameObject::memCurFrame = int(((SDL_GetTicks() / 100) % 6)); // This was not explicitly stated in the book, but it works?
  memX -= 1;
}