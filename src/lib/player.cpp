#include "../include/player.h"

player::player(const loadParams *lP) : SDLGameObject(lP) {

}

void player::draw () {

  SDLGameObject::draw();
}

void player::update() {

  memVel.setX(0);
  memVel.setY(0);

  handleInput();

  memCurFrame = int(((SDL_GetTicks() / 100) % 6));
  SDLGameObject::update();
}

void player::handleInput() {

  vector2d *target = theInputHandler::Instance()->getMousePos();
  memVel = *target - memPos;

  memVel /= 50;

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

  /*
    The below can be OR'd to be WASD or Arrow keys or any keys 
    that would make sense to add multiple bindings for.
    
    ex: 
    if(theInputHandler::Instance()->isKeydown(SDL_SCANCODE_D) || 
        theInputHandler::Instance()->isKeydown(SDL_SCANCODE_RIGHT)) {
      // do stuff
    }
  */

  // Can I shorten theInputHandler::Instance()? Just a note
  if(theInputHandler::Instance()->isKeydown(SDL_SCANCODE_D)) {

    memVel.setX(2);
  }

  if(theInputHandler::Instance()->isKeydown(SDL_SCANCODE_A)) {

    memVel.setX(-2);
  }

  if(theInputHandler::Instance()->isKeydown(SDL_SCANCODE_W)) {

    memVel.setY(-2);
  }

  if(theInputHandler::Instance()->isKeydown(SDL_SCANCODE_S)) {

    memVel.setY(2);
  }

  if(theInputHandler::Instance()->isKeydown(SDL_SCANCODE_E)) {
    
    ;
  }
}

void player::clean() {
 
  ;
}