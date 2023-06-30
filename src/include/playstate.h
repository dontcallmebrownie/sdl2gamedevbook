#ifndef PLAYTATE_H
#define PLAYSTATE_H

#include<iostream>
#include<string>

#include "gamestate.h"

class playState : public gameState {

public:

  virtual void update();
  virtual void render();
  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateId() const {return playId;}

private:

  static const std::string playId;
};

#endif