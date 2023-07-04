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

#define SDL_MAIN_HANDLED
#include "SDL.h"

const int FPS = 60;
const int DELAY_TIME = 16.6f;

Uint32 frameS, frameT;

int main(int argc, char *args[]) {

  std::cout << "Attempting to init Game...\n";

  if(theGame::Instance()->init("GDevBook", 640, 480, false)) {

    std::cout << "\tGame init success!\n\n";

    while(theGame::Instance()->getRunning()) {

      frameS = SDL_GetTicks();

      theGame::Instance()->eventsHandler();
      theGame::Instance()->update();
      theGame::Instance()->render();

      frameT = SDL_GetTicks() - frameS; // Calculating our delta? Idk, maybe.

      if (frameT < DELAY_TIME) {

        SDL_Delay((int)(DELAY_TIME - frameT));
      }
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
