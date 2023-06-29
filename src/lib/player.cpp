#include "../include/player.h"

player::player(const loadParams *lP) : SDLGameObject(lP) {

}

void player::draw () {

  SDLGameObject::draw();
}

void player::update() {

  vector2d *vec = theInputHandler::Instance()->getMousePos();
  memVel = (*vec - memPos) / 100;

  handleInput();

  memCurFrame = int(((SDL_GetTicks() / 100) % 6));
  SDLGameObject::update();
}

void player::handleInput() {

  if(theInputHandler::Instance()->joySticksInitialized()) {

    if(theInputHandler::Instance()->xVal(0, 1) > 0 || theInputHandler::Instance()->xVal(0, 1) < 0) {

      memVel.setX(1 * theInputHandler::Instance()->xVal(0, 1));
    }

    if(theInputHandler::Instance()->yVal(0, 1) > 0 || theInputHandler::Instance()->yVal(0, 1) < 0) {

      memVel.setY(1 * theInputHandler::Instance()->yVal(0, 1));
    }

    if(theInputHandler::Instance()->xVal(0, 2) > 0 || theInputHandler::Instance()->xVal(0, 2) < 0) {

      memVel.setX(1 * theInputHandler::Instance()->xVal(0, 2));
    }

    if(theInputHandler::Instance()->yVal(0, 2) > 0 || theInputHandler::Instance()->yVal(0, 2) < 0) {

      memVel.setY(1 * theInputHandler::Instance()->yVal(0, 2));
    }
  }


    /*
        **BUTTON INFO FOR DS4 Controller**
        ----------------------------------
            0 X Button
            1 0 Button
            2 Square Button
            3 Triangle Button 
            
            4 Share Button
            5 PS Button
            6 Options Button

            7 Left Stick 3 (click) Button
            8 Right Stick 3 (click) Button

            9 Left Trigger 1 (Bumper) Button
            10 Right Trigger 1 (Bumper) Button

            11 DPAD Up
            12 DPAD Down
            13 DPAD Left
            14 DPAD Right
  

    if(theInputHandler::Instance()->getButtonState(0, 14)) {

      memVel.setX(1);
    }
    */

  if(theInputHandler::Instance()->getMouseButtonState(LEFT)) {

  }
}

void player::clean() {
 
  ;
}