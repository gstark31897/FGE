#ifndef H_RENDERABLE
#define H_RENDERABLE

#include "rendermanager.h"


class Renderable
{
public:
    virtual void render(SDL_Renderer *renderer) {};
    virtual void update() {};
};

#endif
