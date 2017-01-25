#include <SDL2/SDL.h>
#include <iostream>

#include "rendermanager.h"
#include "animation.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480


void render(SDL_Window *window)
{
    bool quit = false;
    size_t last = 0;
    size_t current = SDL_GetPerformanceCounter();
    SDL_Event e;
    //SDL_Surface *screenSurface = NULL;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        std::cerr << "SDL could not initialize renderer: " << SDL_GetError() << std::endl;
        return;
    }

    RenderManager *renderManager = new RenderManager(renderer);
    Animation *anim = new Animation(10.0);
    renderManager->registerRenderable(anim);
    anim->addFrame("spikey.jpg", 0,  0, 100, 100, 0, 0, 100, 100);
    anim->addFrame("spikey.jpg", 10, 0, 110, 100, 0, 0, 110, 100);
    anim->addFrame("spikey.jpg", 20, 0, 120, 100, 0, 0, 120, 100);
    anim->addFrame("spikey.jpg", 10, 0, 110, 100, 0, 0, 110, 100);
    while (!quit)
    {
        last = current;
        current = SDL_GetPerformanceCounter();

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        renderManager->update((current-last)*1000 / SDL_GetPerformanceFrequency());
        renderManager->render();

        SDL_UpdateWindowSurface(window);

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }
}


int main(int argc, char *args[])
{
    SDL_Window *window = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize: " << SDL_GetError() << std::endl;
        return -1;
    }

    window = SDL_CreateWindow("FGE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cerr << "SDL could not create window: " << SDL_GetError() << std::endl;
        return -1;
    }

    render(window);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
