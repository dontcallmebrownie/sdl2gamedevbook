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

bool running = false;


bool init(const char* title, int height, int width, int flags) {
  std::cout << "init() Called!\n";

  // initialize SDL
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, flags);

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

    if(win != 0) {

    render = SDL_CreateRenderer(win, -1, 0);
    // **Add error checking here**

    }
  }
  else {

    std::cout << "ERROR: " << SDL_GetError() << std::endl;

  return false;
  }

return true;
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

void BGRender(int r, int g, int b, int a) {

  SDL_SetRenderDrawColor(render, r, g, b, a);
  SDL_RenderClear(render);
  SDL_RenderPresent(render);
}

int main(int argc, char *args[]) {

  if (init("Sophia", 800, 600, SDL_WINDOW_SHOWN)) {

    running = true;
  }
  else {

    return 1;
  }
  
  load();
  
  while (running) {

    // eventsHandler();
    // update();
    // render();

    BGRender(0, 255, 0, 0);
    SDL_Delay(2000);
  }

  close();

return 0;
}
