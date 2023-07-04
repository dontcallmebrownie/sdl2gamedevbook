#ifndef MENUBUTON_H
#define MENUBUTON_H


#include "vector2d.h"
#include "inputhandler.h"

class menuButton: public SDLGameObject {

public:

  menuButton(const loadParams *lP, void (*callback)());

  virtual void draw();
  virtual void update();
  virtual void clean();
  
private:

  void (*memCallback)();
  bool memReleased;

  enum buttonState {
  
    MOUSEOUT = 0,
    MOUSEOVER = 1,
    CLICKED = 2
  };
};



#endif