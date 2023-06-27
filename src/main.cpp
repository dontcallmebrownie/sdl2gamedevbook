/*************************************************************
*
*    Sophia Game
*    (C) David Cramer 2023
*	
*	This is code being written in the course of working
*	through SDL Game Development and commits will
* 	reflect as such until fully worked through building
* 	the framework for a full 2d game. Said framework 
*	will be based on this book but heavily modified and
*	used only as the foundation of this software.
*	As much as possible code will be rewritten, removed,
*	and refactored so as to avoid copyright issues with 
* 	the published code. 
*
*	Any and all copyright concerns should be brought,
*	as soon as practicable, directly to: 
*	David@erraticsoft.com so they can be addressed 
*	in good faith.  
*
*************************************************************/

#include "./include/game.h"

int main(int argc, char *args[]) {

  std::cout << "Attempting to init Game...\n";

  if(theGame::Instance()->init("Sophia", 640, 480, false)) {

    std::cout << "\tGame init success!\n";

    while(theGame::Instance()->getRunning()) {

      theGame::Instance()->eventsHandler();
      theGame::Instance()->update();
      theGame::Instance()->render();

      SDL_Delay(10);      
    }
  }
  else {

    std::cout << "**Game init failed!**\n";
  return -1;
  }

  std::cout << "Game closing!\n";

  theGame::Instance()->clean();

return 0;
}
