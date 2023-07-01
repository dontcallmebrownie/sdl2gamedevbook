#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include<iostream>
#include<string>

#include "gamestate.h"


class gameObject;

class pauseState : public gameState {

public:

  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  std::string getStateId() const {return pauseId;}

private:

  static void pauseToMain();
  static void resumePlay();

  static const std::string pauseId;

  std::vector<gameObject*> memGameObjects;
};

#endif