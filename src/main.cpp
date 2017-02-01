#include <SDL2/SDL.h>
#include <iostream>

#include "rendermanager.h"
#include "animation.h"
#include "combo.h"
#include "keyboard.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480


void render(SDL_Window *window)
{
    bool quit = false;
    size_t last = 0;
    size_t current = SDL_GetPerformanceCounter();
    float deltaTime = 0;
    SDL_Event e;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        std::cerr << "SDL could not initialize renderer: " << SDL_GetError() << std::endl;
        return;
    }

    std::vector<SDL_Keycode> abba;
    abba.push_back(SDLK_a);
    abba.push_back(SDLK_b);
    abba.push_back(SDLK_b);
    abba.push_back(SDLK_a);

    ComboRecognizer *combo = new ComboRecognizer(250.0f);
    combo->addCombo(abba);
    KeyboardManager km;
    km.registerKeyListener(combo);

    RenderManager *renderManager = new RenderManager(renderer);
    Animation *anim = new Animation(10.0);
    renderManager->registerRenderable(anim);
    anim->addFrame("spikey.jpg", 0,  0, 100, 100, 0, 0, 100, 100);

    while (!quit)
    {
        last = current;
        current = SDL_GetPerformanceCounter();
        deltaTime = (current-last)*1000 / SDL_GetPerformanceFrequency();

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        renderManager->update(deltaTime);
        renderManager->render();

        combo->update(deltaTime);

        SDL_UpdateWindowSurface(window);

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                quit = true;
            if (e.type == SDL_KEYDOWN)
            {
                km.keyDown(e.key.keysym.sym);
            }
            if (e.type == SDL_KEYUP)
            {
                km.keyUp(e.key.keysym.sym);
            }
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
