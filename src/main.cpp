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
#include <string>
#include <fstream>

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "./include/timer.h"




// Globals --Don't love this but here for now
SDL_Window *win = 0;
SDL_Renderer *render = 0; // Note: Why are we setting this to 0? Error checking? NULL works for that too
                          // --Keep an eye on this--




int init() {
  std::cout << "init() Called!\n";

  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

    win = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    std::cout << "\nChecking systems we care about...\n";

    if(SDL_WasInit(SDL_INIT_VIDEO) != 0) {

      std::cout << "\tVideo initialized! \n";
    }
    
    if(SDL_WasInit(SDL_INIT_AUDIO) != 0) {

      std::cout << "\tAudio initialized! \n";
    }

    if(SDL_WasInit(SDL_INIT_TIMER) != 0) {

      std::cout << "\tTimer initialized! \n\n";
    }






    if (win != 0) {
      
      render = SDL_CreateRenderer(win, -1, 0);
      // **Add error checking here!**
    }
  } 
  else {
    std::cout << "ERROR: " << SDL_GetError() << std::endl;
  }

return 0;
}

int load() {
  std::cout << "load() Called!\n";

return 0;
}

int close() {
  std::cout << "close() Called!\n";

  // Free everything like the good programmer we aren't
  win = 0;
  render = 0;
 

  // Quit all extensions
  TTF_Quit();
  Mix_Quit();
  IMG_Quit();

  // Quit SDL
  SDL_Quit(); 

return 0;
}

int main(int argc, char *args[]) {

  init();
  load();
  
  // Everything logic goes between here and close();


  // simple render test
  SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
  SDL_RenderClear(render);
  SDL_RenderPresent(render);
  SDL_Delay(2000);

  // SMTPE Texture render test




  
  
  
  
  
  close();

return 0;
}
