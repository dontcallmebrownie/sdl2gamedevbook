#include "../include/texman.h"

texMan *texMan::inst = 0;

bool texMan::load(std::string fileName, std::string id, SDL_Renderer *screen) {
  std::cout << "texMan.load() called!\n";

  SDL_Surface* tempS = IMG_Load(fileName.c_str());

  if(tempS == 0) {
    
    std::cout << "\t**load failed!**\n";
  return false;
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface(screen, tempS);
  SDL_FreeSurface(tempS);
  
  // Add to tex map
  if(texture != 0) {

    texMap[id] = texture;
  return true;
  }
return false;
}

void texMan::draw(std::string id, int x, int y, int w, int h, SDL_Renderer *screen, SDL_RendererFlip flip) {

  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = w;
  srcRect.h = destRect.h = h;
  
  destRect.x = x;
  destRect.y = y;
  
  SDL_RenderCopyEx(screen, texMap[id], &srcRect, &destRect, 0, 0, flip);
}

void texMan::drawFrame(std::string id, int x, int y, int w, int h, int curRow, int curFrame, SDL_Renderer *screen, SDL_RendererFlip flip) {

  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = w * curFrame;
  srcRect.y = h * (curRow - 1);
  srcRect.w = destRect.w = w;
  srcRect.h = destRect.h = h;

  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(screen, texMap[id], &srcRect, &destRect, 0, 0, flip);
}