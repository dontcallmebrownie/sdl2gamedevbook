#include "../include/gamestatemachine.h"

void gameStateMachine::pushState(gameState *state) {

  memGameStates.push_back(state);
  memGameStates.back()->onEnter();
}

void gameStateMachine::changeState(gameState *state) {

  if(!memGameStates.empty()) {

    if(memGameStates.back()->getStateId() == state->getStateId()) {

    return;
    }

    if(memGameStates.back()->onExit()) {

      delete memGameStates.back();
      memGameStates.pop_back();
    }
  }

  memGameStates.push_back(state);
  memGameStates.back()->onEnter();
}

void gameStateMachine::popState() {

  if(!memGameStates.empty()) { 
  
    if(memGameStates.back()->onExit()) {

      delete memGameStates.back();
      memGameStates.pop_back();
    }
  }
}