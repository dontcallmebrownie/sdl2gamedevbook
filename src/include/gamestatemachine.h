#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H


#include "gamestate.h"

class gameStateMachine {

public:

  void pushState(gameState *state);
  void changeState(gameState *state);
  void popState();

private:

  std::vector<gameState*> memGameStates;

};
#endif