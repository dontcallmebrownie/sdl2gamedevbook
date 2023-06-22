/*************************************************************
*
*    Sophia Game
*    (C) David Cramer 2023
*
*    This is a game written in SDL2 for home computers
*
*
*
*         Things I actually need to modify or access
*           screen
*           timer
*           room
*
*
*         Things I dont need to modify or access
*           Window
*
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



#include <iostream>
#include <fstream>

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "./include/timer.h"



int init() {
  std::cout << "init() Called!\n";

return 0;
}

int load() {
  std::cout << "load() Called!\n";

  int init_status = SDL_Init(SDL_INIT_EVERYTHING);

  std::cout << "\tSDL_Init status: " + init_status << std::endl;

return 0;
}

int close() {
  std::cout << "close() Called!\n";
 
  TTF_Quit();
  Mix_Quit();
  IMG_Quit();
  
  SDL_Quit(); 

return 0;
}

int main(int args, char *argv[]) {

  init();
  load();
  
  
  
  
  
  
  close();

return 0;
}
