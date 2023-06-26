
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

  go = new gameObject();
  p = new player();
  e = new enemy();

  go->load(100, 100, 126, 82, "animate");
  p->load(300, 300, 128, 82, "animate");
  e->load(0, 0, 128, 82, "animate");

  memGameObjects.push_back(go);
  memGameObjects.push_back(p);
  memGameObjects.push_back(e);

return true;
}

void Game::render() {
  
  SDL_RenderClear(screen);

  for(std::vector<gameObject>::size_type i = 0; i != memGameObjects.size(); i++) {

    memGameObjects[i]->draw(screen);
  }

  SDL_RenderPresent(screen);
}

void Game::update() {

  for(std::vector<gameObject>::size_type i = 0; i != memGameObjects.size(); i++) {

    memGameObjects[i]->update();
  }
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