#ifndef TEXMAN_H
#define TEXMAN_H

#include <iostream>
#include <map>
#include <string>

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

class texMan {

public:

  static texMan* Instance() {

    if(inst == 0)
    {

      inst = new texMan();
    return inst;
    }
  return inst;
  }

  typedef texMan TheTextureManager;


  bool load(std::string fileName, std::string id, SDL_Renderer* screen);
  void draw(std::string id, int x, int y, int w, int h, SDL_Renderer *screen, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawFrame(std::string id, int x, int y, int w, int h, int curRow, int curFrame, SDL_Renderer *screen, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void clearTex(std::string id);

private:

  std::map<std::string, SDL_Texture*> texMap;

  texMan() {}
  ~texMan() {}  
 
  static texMan *inst;
};

  typedef texMan theTexMan;


#endif