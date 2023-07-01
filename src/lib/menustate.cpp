#include "../include/menustate.h"
#include "../include/menubutton.h"

const std::string menuState::menuId = "MENU";

void menuState::update() {

  for(int i = 0; i < memGameObjects.size(); i++) {

    memGameObjects[i]->update();
  }
}

void menuState::render() {

   for(int i = 0; i < memGameObjects.size(); i++) {

    memGameObjects[i]->draw();
  }
}

bool menuState::onEnter() {

  std::cout << "Entering Menu State!\n";

  if(!theTexMan::Instance()->load("../assets/button.png", "playbutton", theGame::Instance()->getRenderer())) {

  return false;
  }

  if(!theTexMan::Instance()->load("../assets/exit.png", "exitbutton", theGame::Instance()->getRenderer())) {

  return false;
  }

  gameObject *button1 = new menuButton(new loadParams(100, 100, 400, 100, "playbutton"), menuToPlay);
  gameObject *button2 = new menuButton(new loadParams(100, 300, 400, 100, "exitbutton"), exitFromMenu);

  memGameObjects.push_back(button1);
  memGameObjects.push_back(button2);

return true;
}

bool menuState::onExit() {

  for(int i = 0; i < memGameObjects.size(); i++) {
    
    memGameObjects[i]->clean();
  }

  memGameObjects.clear();

  theTexMan::Instance()->clearTex("playbutton");
  theTexMan::Instance()->clearTex("exitbutton");
  std::cout << "Exiting Menu State!\n";

return true;
}

void menuState::menuToPlay() {

  std::cout << "\t**Play button pressed!**\n";
  theGame::Instance()->getStateMachine()->changeState(new playState());
}

void menuState::exitFromMenu() {

  std::cout << "\t**Exit button pressed!**\n";
  theGame::Instance()->quit();
}