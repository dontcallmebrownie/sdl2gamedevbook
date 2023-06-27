#include "../include/sdlgameobject.h"
#include "../include/game.h"

SDLGameObject::SDLGameObject(const loadParams *lP) : gameObject(lP) {

  memX = lP->getX();
  memY = lP->getY();
  memW = lP->getW();
  memH = lP->getH();

  memId = lP->getId();

  memCurRow = 1;
  memCurFrame = 1;
}

void SDLGameObject::draw() {

  texMan::Instance()->drawFrame(memId, memX, memY, memW, memH, memCurRow, memCurFrame, theGame::Instance()->getRenderer());
}

void SDLGameObject::update() {

;
}

void SDLGameObject::clean() {

;
}