#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H


#include "gameobject.h"
#include "vector2d.h"


class SDLGameObject : public gameObject {

public:

  SDLGameObject(const loadParams *lP);
  
  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
  
  vector2d memPos;
  vector2d memVel;
  vector2d memAcc;
  
  int memW;
  int memH;
  
  int memCurRow;
  int memCurFrame;
  
  std::string memId;
};

#endif