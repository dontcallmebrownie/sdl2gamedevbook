#include "../include/inputhandler.h"

  inputHandler::inputHandler() {
    
    for(int i = 0; i < 3; i++) {

      memMouseButtonStates.push_back(false);
    }  
  }

void inputHandler::initializeJoySticks () {

  if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {

    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
  }

  if(SDL_NumJoysticks() > 0) {

    for(int i = 0; i < SDL_NumJoysticks(); i++) {

      SDL_Joystick *joy = SDL_JoystickOpen(i);

      // I think this can be optimzed
      if(SDL_JoystickOpen(i)) { // OH MY GOD THIS SHIT DROVE ME CRAZY ***DO NOT CHECK FOR == 0, CHECK FOR 1*** FUCK.

        memJoysticks.push_back(joy);
        memJSVals.push_back(std::make_pair(new vector2d(0, 0), new vector2d(0, 0)));

        std::vector<bool> tmpButtons;

        for(int j = 0; j < SDL_JoystickNumButtons(joy); j++) {

          tmpButtons.push_back(false);
        }
        
        memButtonStates.push_back(tmpButtons);
      }
      else {

        std::cout << "ERROR: " << SDL_GetError() << std::endl;
      }
    }

    SDL_JoystickEventState(SDL_ENABLE);
    memJSInitialized = true;

    std::cout << memJoysticks.size() << " Joystick(s) Initialized!\n";
  }
  else {

    std::cout << "\t**No Joysticks found!**\n";
    memJSInitialized = false;
  }
}

void inputHandler::clean() {
  if(memJSInitialized) {
    for(int i = 0; i < SDL_NumJoysticks(); i++) {

    SDL_JoystickClose(memJoysticks[i]);
    }
  }
}

void inputHandler::update() {

  SDL_Event event;

  while(SDL_PollEvent(&event)) {

    switch(event.type) {

      case SDL_QUIT:
        theGame::Instance()->quit();
        break;
      
      case SDL_JOYAXISMOTION:
        onJoystickAxisMove(event);
        break;
      
      case SDL_JOYBUTTONDOWN:
        onJoystickButtonDown(event);
        break;

      case SDL_MOUSEMOTION:
        onMouseMove(event);
        break;
      
      case SDL_MOUSEBUTTONDOWN:
        onMouseClick(event);
        break;

      case SDL_MOUSEBUTTONUP:
        onMouseUnClick(event);
        break;

      case SDL_KEYDOWN:
        onKeydown();
        break;
      
      case SDL_KEYUP:
        onKeyup();
        break;

      default:
        break;
    }
  }
}

int inputHandler::xVal(int joy, int stick) {

  if(memJSVals.size() > 0) {

    if(stick == 1) {

    return memJSVals[joy].first->getX();
    }
    else if(stick == 2) {

    return memJSVals[joy].second->getX();
    }
  }
return 0;
}

int inputHandler::yVal(int joy, int stick) {

  if(memJSVals.size() > 0) {

    if(stick == 1) {

    return memJSVals[joy].first->getY();
    }
    else if(stick == 2) {

    return memJSVals[joy].second->getY();
    }
  }
return 0;
}

bool inputHandler::isKeydown (SDL_Scancode key) {

  if(memKeystate != 0) {
    
    if(memKeystate[key]) {

    return true;
    }
    else {

    return false;
    }
  }
return false;
}

void inputHandler::onKeydown() {

  memKeystate = SDL_GetKeyboardState(0);
}

void inputHandler::onKeyup() {
  
  memKeystate = SDL_GetKeyboardState(0);
}

void inputHandler::onMouseMove(SDL_Event &event) {

  memMousePos->setX(event.motion.x);
  memMousePos->setY(event.motion.y);
}

void inputHandler::onMouseClick(SDL_Event &event) {

  if(event.button.button == SDL_BUTTON_LEFT) {

    memMouseButtonStates[LEFT] = true;
  }

  if(event.button.button == SDL_BUTTON_MIDDLE) {
        
    memMouseButtonStates[MIDDLE] = true;
  }

  if(event.button.button == SDL_BUTTON_RIGHT) {
       
    memMouseButtonStates[RIGHT] = true;        
  }
}

void inputHandler::onMouseUnClick(SDL_Event &event) {

  if(event.button.button == SDL_BUTTON_LEFT) {

    memMouseButtonStates[LEFT] = false;
  }

  if(event.button.button == SDL_BUTTON_MIDDLE) {
       
    memMouseButtonStates[MIDDLE] = false;
  }

  if(event.button.button == SDL_BUTTON_RIGHT) {
        
    memMouseButtonStates[RIGHT] = false;        
  }
}

void inputHandler::onJoystickAxisMove(SDL_Event &event) {

      /*  **AXES FOR DS4 Controller**
          ---------------------------
              0 & 1 Left Stick
              2 & 3 Right Stick
              4 Left Trigger
              5 Right strigger
      */ 
                                          
  int whichOne = event.jaxis.which;   

  if(event.jaxis.axis == 0) { // Left stick Left/Right

    if(event.jaxis.value > memJSDZone) {
          
      memJSVals[whichOne].first->setX(1);
    }
    else if(event.jaxis.value < -memJSDZone) {

      memJSVals[whichOne].first->setX(-1);
    }
    else {

      memJSVals[whichOne].first->setX(0);
    }
  }

  if(event.jaxis.axis == 1) { // Left stick Up/Down

    if(event.jaxis.value > memJSDZone) {
          
      memJSVals[whichOne].first->setY(1);
    }
    else if(event.jaxis.value < -memJSDZone) {

      memJSVals[whichOne].first->setY(-1);
    }
    else {

      memJSVals[whichOne].first->setY(0);
    }
  }

  if(event.jaxis.axis == 2) { // Right stick Left/Right

    if(event.jaxis.value > memJSDZone) {
          
      memJSVals[whichOne].second->setX(1);
    }
    else if(event.jaxis.value < -memJSDZone) {

      memJSVals[whichOne].second->setX(-1);
    }
    else {

      memJSVals[whichOne].second->setX(0);
    }
  }

  if(event.jaxis.axis == 3) { // Right stick Up/Down

    if(event.jaxis.value > memJSDZone) {
          
        memJSVals[whichOne].second->setY(1);
    }
    else if(event.jaxis.value < -memJSDZone) {

      memJSVals[whichOne].second->setY(-1);
    }
    else {

      memJSVals[whichOne].second->setY(0);
    }
  }
}

void inputHandler::onJoystickButtonDown(SDL_Event &event) {

  int whichOne = event.jaxis.which; 

  memButtonStates[whichOne][event.jbutton.button] = true; 
}

void inputHandler::onJoystickButtonUp(SDL_Event &event) {

  int whichOne = event.jaxis.which; 

  memButtonStates[whichOne][event.jbutton.button] = false;  
}