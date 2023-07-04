#include<iostream>

#include "../include/gamestatemachine.h"

void gameStateMachine::pushState(gameState *state) {

  memGameStates.push_back(state);
  memGameStates.back()->onEnter();
}

void gameStateMachine::changeState(gameState *state) {

  std::cout << state->getStateId() << std::endl;

  if(!memGameStates.empty()) {

    if(memGameStates.front()->getStateId() == state->getStateId()) {

    return;
    }

    if(memGameStates.front()->onExit()) {

      delete memGameStates.front();
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

void gameStateMachine::render() {

  if(!memGameStates.empty()) {

    memGameStates.back()->render();
  }
}

void gameStateMachine::update() {
  
  if(!memGameStates.empty()) {

    memGameStates.back()->update();
  }
}