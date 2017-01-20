#ifndef H_RENDERMANAGER
#define H_RENDERMANAGER

#include <map>
#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "renderable.h"


class RenderManager
{
private:
    SDL_Renderer *m_renderer;
    std::map<std::string, SDL_Texture*> m_textures;
    std::vector<Renderable*>            m_subjects;

public:
    RenderManager(SDL_Renderer *renderer);
    ~RenderManager();

    void registerRenderable(Renderable *subject);
    void unregisterRenderable(Renderable *subject);

    bool loadTexture(std::string path);

    void update();
    void render();
};

#endif
