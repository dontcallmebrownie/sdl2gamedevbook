#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <vector>

#include "SDL2/SDL.h"
#include "./game.h"

  enum mouseButtons {

    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
  };


class inputHandler {

public:

  static inputHandler *Instance() {

    if (inst == 0) {

      inst = new inputHandler();
    }
  return inst;  
  }

  void initializeJoySticks();
  bool joySticksInitialized() {return memJSInitialized;}
  void update();
  void clean();

  int xVal(int joy, int stick);
  int yVal(int joy, int stick);
  bool getButtonState(int joy, int buttonNumber) {return memButtonStates[joy][buttonNumber];}
  
  bool getMouseButtonState(int buttonNumber) {return memMouseButtonStates[buttonNumber];}
  vector2d *getMousePos() {return memMousePos;}

private:

  inputHandler();
  static inputHandler *inst;
  bool memJSInitialized;
  const int memJSDZone = 10000;

  std::vector<SDL_Joystick*> memJoysticks;
  std::vector<std::pair<vector2d*, vector2d*>> memJSVals;
  std::vector<std::vector<bool>> memButtonStates;
  std::vector<bool> memMouseButtonStates;
  vector2d *memMousePos = new vector2d;

};

typedef inputHandler theInputHandler; 


#endif