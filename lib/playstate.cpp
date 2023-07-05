#include "../include/playstate.h"

const std::string playState::playId = "PLAY";

void playState::update() {
   
  for(int i = 0; i < memGameObjects.size(); i++) {
     
      memGameObjects[i]->update();
    }
}

void playState::render() {

   for(int i = 0; i < memGameObjects.size(); i++) {

    memGameObjects[i]->draw();
  }
}

bool playState::onEnter() {

  std::cout << "Entering Play State!\n";

  if(!theTexMan::Instance()->load("./assets/helicopter.png", "helicopter", theGame::Instance()->getRenderer())) {
    
  return false;
  }


  gameObject *p = new player(new loadParams(100, 100, 128, 55, "helicopter"));

  playState::memGameObjects.push_back(p);
  
return true;
}

bool playState::onExit() {

  for(int i = 0; i < memGameObjects.size(); i++) {

    memGameObjects[i]->clean();
  }
  memGameObjects.clear();
  theTexMan::Instance()->clearTex("helicopter");

  std::cout << "Exiting Play State!\n";

return true;
}