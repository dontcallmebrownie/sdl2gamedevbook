#include "../include/menustate.h"

const std::string menuState::menuId = "MENU";

void menuState::update() {

  // nothing yet
}

void menuState::render() {

  // nothing yet
}

bool menuState::onEnter() {

  std::cout << "Entering Menu State!\n";

return true;
}

bool menuState::onExit() {

  std::cout << "Exiting Menu State!\n";

return true;
}