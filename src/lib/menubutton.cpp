#include "../include/menubutton.h"
#include "../include/inputhandler.h"

menuButton::menuButton(const loadParams *lP, void (*callback)()) : SDLGameObject(lP), memCallback(callback) {

  memCurFrame = MOUSEOUT;
}

void menuButton::draw() {

  SDLGameObject::draw();
}

void menuButton::update() {
  
  vector2d *mousePos = theInputHandler::Instance()->getMousePos();

  if(mousePos->getX() < (memPos.getX() + memW) && 
    mousePos->getX() > memPos.getX() && 
    mousePos->getY() < (memPos.getY() + memH) &&
    mousePos->getY() > memPos.getY()) {

    memCurFrame = MOUSEOVER;

    if(theInputHandler::Instance()->getMouseButtonState(LEFT) && memReleased) {

      memCurFrame = CLICKED;
      memCallback();
      memReleased = false;
    }
    else if(theInputHandler::Instance()->getMouseButtonState(LEFT)) {

      memReleased = true;
      memCurFrame = MOUSEOVER;
    }
  }
  else {

    memCurFrame = MOUSEOUT;
  }
}

void menuButton::clean() {
  
  SDLGameObject::clean();
}