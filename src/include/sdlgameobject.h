#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H


#include "gameobject.h"

class SDLGameObject : public gameObject {

public:

  SDLGameObject(const loadParams *lP);
  
  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
  
  int memX;
  int memY;
  
  int memW;
  int memH;
  
  int memCurRow;
  int memCurFrame;
  
  std::string memId;
};

#endif