
#include "../include/game.h"

bool Game::init(const char* title, int height, int width, bool fs) {
  std::cout << "init() Called!\n";


  // init SDL
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {

    std::cout << "SDL init success!\n";

    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, fs);
    if(win != 0) {

      std::cout << "\tWindow created!\n"; 

      screen = SDL_CreateRenderer(win, -1, 0);
      if (screen != 0) {

        std::cout << "\tRenderer created!\n\n";

        SDL_SetRenderDrawColor(screen, 0, 255, 0, 255);
      } 
      else {

       std::cout << "Renderer failed to init!\n";
      return false;
      }
    }
    else {
      
      std::cout << "Window failed to init!\n";
      return false; 
    }
  }
  else {

    std::cout << "**ERROR** SDL failed to init!: " << SDL_GetError() << std::endl;
  return false;
  }

  std::cout << "SDL init success!\n";
  running = true;

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

  if(!theTexMan::Instance()->load("../assets/animate-alpha.png", "animate", screen)) {

  return false;
  }

return true;
}

void Game::render() {
  
  SDL_RenderClear(screen);

  theTexMan::Instance()->draw("animate", 0, 0, 128, 82, screen);
  theTexMan::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, curFrame, screen);

  SDL_RenderPresent(screen); // draw to the screen
}

void Game::update() {
  
  curFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::eventsHandler() {
  
  SDL_Event event;
  
  if(SDL_PollEvent(&event)) {
  
    switch (event.type) {
      
    case SDL_QUIT:
      running = false;
      break;
    default:
      break;
    }
  }
}

void Game::clean() {
  std::cout << "clean() Called!\n";

  // Free everything like the good programmer we aren't
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(screen);
 
  // Quit all extensions
  TTF_Quit();
  Mix_Quit();
  IMG_Quit();

  // Quit SDL
  SDL_Quit();
}