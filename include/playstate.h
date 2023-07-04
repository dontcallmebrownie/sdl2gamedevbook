#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include<iostream>
#include<string>

#include "gamestate.h"
#include "player.h"

class gameObject;

class playState : public gameState {

public:

  //virtual ~playState() = default;

  virtual void update();
  virtual void render();
  virtual bool onEnter();
  virtual bool onExit();

  std::string getStateId() const {return playId;}

private:

  static const std::string playId;

  std::vector<gameObject*> memGameObjects;
};

#endif