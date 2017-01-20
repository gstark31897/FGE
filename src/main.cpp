#include <SDL2/SDL.h>
#include <iostream>

#include "rendermanager.h"
#include "sprite.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480


void render(SDL_Window *window)
{
    bool quit = false;
    SDL_Event e;
    SDL_Surface *screenSurface = NULL;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cerr << "SDL could not initialize renderer: " << SDL_GetError() << std::endl;
        return;
    }

    RenderManager *renderManager = new RenderManager(renderer);
    Sprite *sprite = new Sprite(renderManager, "spikey.jpg", 0.0f, 0.0f, 100.0f, 100.0f);
    renderManager->registerRenderable(sprite);
    while (!quit)
    {
        screenSurface = SDL_GetWindowSurface(window);
        SDL_RenderClear(renderer);
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

        renderManager->update();
        renderManager->render();

        SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);

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
