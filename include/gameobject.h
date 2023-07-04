#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "./loadparams.h"
#include "./texman.h"


class gameObject {

public:

  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

protected:

  gameObject (const loadParams *lP);
  virtual ~gameObject() {};

};

#endif