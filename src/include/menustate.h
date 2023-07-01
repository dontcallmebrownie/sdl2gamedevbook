#ifndef MENUSTATE_H
#define MENUSTATE_H

#include<iostream>
#include<string>

#include "gamestate.h"
#include "gameobject.h"


class menuState : public gameState {

public:

  virtual void update();
  virtual void render();
  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateId() const {return menuId;}

private:

  static void menuToPlay();
  static void exitFromMenu();

  std::vector<gameObject*> memGameObjects;

  static const std::string menuId;
};


#endif