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

#include "include/game.h"

Game *game = 0;

int main(int argc, char *args[]) {

  game = new Game();

  game->init("Sophia", 640, 480, false);
  
  while (game->getRunning()) {

    game->eventsHandler();
    game->update();
    game->render();
    SDL_Delay(10);
  }

  game->clean();

return 0;
}
