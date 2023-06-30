#include "../include/playstate.h"

const std::string playState::playId = "PLAY";

void playState::update() {

  // nothing yet
}

void playState::render() {

  // nothing yet
}

bool playState::onEnter() {

  std::cout << "Entering Play State!\n";

return true;
}

bool playState::onExit() {

  std::cout << "Exiting Play State!\n";

return true;
}