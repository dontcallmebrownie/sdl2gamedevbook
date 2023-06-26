#include "../include/gameobject.h"
#include "../include/texman.h" // Am I supposed to assume this is placed here?

void gameObject::load(int x, int y, int w, int h, std::string id) {

  memX = x;
  memY = y;
  memW = w;
  memH = h; 
  
  memId = id;
  memCurRow = 1;
  memCurFrame = 1;
}

void gameObject::draw(SDL_Renderer *screen) {
  
  texMan::Instance()->drawFrame(memId, memX, memY, memW, memH, memCurRow, memCurFrame, screen);
}

void gameObject::update() {

  memX += 1;
}

void gameObject::clean() {
 
  ;
}