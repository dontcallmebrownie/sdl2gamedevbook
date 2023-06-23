#include "../include/texman.h"

texMan *texMan::inst;

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

void texMan::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *screen, SDL_RendererFlip flip) {

  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  
  destRect.x = x;
  destRect.y = y;
  
  SDL_RenderCopyEx(screen, texMap[id], &srcRect, &destRect, 0, 0, flip);
}

void texMan::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *screen, SDL_RendererFlip flip) {

  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = width * currentFrame;
  srcRect.y = height * (currentRow - 1);
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;

  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(screen, texMap[id], &srcRect, &destRect, 0, 0, flip);
}