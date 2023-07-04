#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <vector>

#include "SDL.h"
#include "game.h"

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
  bool isKeydown(SDL_Scancode key);
  
  
  bool getMouseButtonState(int buttonNumber) {return memMouseButtonStates[buttonNumber];}
  vector2d *getMousePos() {return memMousePos;}


  // Consolodate input stuff
  void onKeydown();
  void onKeyup();

  void onMouseMove(SDL_Event &event);
  void onMouseClick(SDL_Event &event);
  void onMouseUnClick(SDL_Event &event); // These are shorter then MouseButtonDown/Up 

  void onJoystickAxisMove(SDL_Event &event);
  void onJoystickButtonDown(SDL_Event &event);
  void onJoystickButtonUp(SDL_Event &event);

private:

  inputHandler();
  static inputHandler *inst;
  bool memJSInitialized;
  const int memJSDZone = 10000;
  const Uint8 *memKeystate;

  std::vector<SDL_Joystick*> memJoysticks;
  std::vector<std::pair<vector2d*, vector2d*>> memJSVals;
  std::vector<std::vector<bool>> memButtonStates;
  std::vector<bool> memMouseButtonStates;
  vector2d *memMousePos = new vector2d;

};

typedef inputHandler theInputHandler; 


#endif