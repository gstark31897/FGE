#include "rendermanager.h"

#include <SDL2/SDL_image.h>

#include <iostream>

using namespace std;


RenderManager::RenderManager(SDL_Renderer *renderer)
{
    m_renderer = renderer;
}

RenderManager::~RenderManager()
{

}

void RenderManager::registerRenderable(Renderable *subject)
{
    m_subjects.push_back(subject);
    subject->renderManagerRegistered(this);
}

void RenderManager::unregisterRenderable(Renderable *subject)
{
    for (std::vector<Renderable*>::iterator it; it != m_subjects.end(); ++it)
    {
        if (*it == subject)
        {
            m_subjects.erase(it);
            break;
        }
    }
}

SDL_Texture* RenderManager::loadTexture(string path)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL)
    {
        std::cerr << "Unable to load texture: " << path << std::endl;
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    m_textures[path] = texture;
    return texture;
}

void RenderManager::update(float deltaTime)
{
    for (std::vector<Renderable*>::iterator it = m_subjects.begin(); it != m_subjects.end(); ++it)
    {
        (*it)->update(deltaTime);
    }
}

void RenderManager::render()
{
    for (std::vector<Renderable*>::iterator it = m_subjects.begin(); it != m_subjects.end(); ++it)
    {
        (*it)->render(m_renderer);
    }
    SDL_RenderPresent(m_renderer);
}
