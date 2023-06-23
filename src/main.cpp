/*************************************************************
*
*    Sophia Game
*    (C) David Cramer 2023
*
*************************************************************/



/*

TODO: #1 init all systems                 []
  * Add error checking for init()         []

TODO: #2 load all files                   []
  * Add error checking for load()         []

TODO: #3 create a window                  []

TODO: #4 create a screen renderer         []



*/


#include "include/game.h"

Game *game = 0;

int main(int argc, char *args[]) {

  game = new Game();

  game->init("Sophia", 640, 480, false);
  
  while (game->getRunning()) {

    game->eventsHandler();
    game->update();
    game->render();
  }

  game->clean();

return 0;
}
