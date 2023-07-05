#include "../include/sdlgameobject.h"
#include "../include/game.h"

SDLGameObject::SDLGameObject(const loadParams *lP) : gameObject(lP), memPos(lP->getX(), lP->getY()), memVel(0, 0), memAcc(0,0) {

  memW = lP->getW();
  memH = lP->getH();

  memId = lP->getId();

  memCurRow = 1;
  memCurFrame = 1;
}

void SDLGameObject::draw() {

  if(memVel.getX() > 0)
  {
    texMan::Instance()->drawFrame(memId, (int)memPos.getX(), (int)memPos.getY(), memW, memH, memCurRow, memCurFrame, theGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
  }
  else {

    texMan::Instance()->drawFrame(memId, (int)memPos.getX(), (int)memPos.getY(), memW, memH, memCurRow, memCurFrame, theGame::Instance()->getRenderer());
  }

}

void SDLGameObject::update() {

    memVel += memAcc;
    memPos += memVel;
}

void SDLGameObject::clean() {

;
}