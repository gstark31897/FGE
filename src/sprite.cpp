#include "sprite.h"

using namespace std;


Sprite::Sprite(string texture, int x, int y, int width, int height)
{
    m_rect = new SDL_Rect();
    *m_rect = {x, y, width, height};
    m_texture = texture;
}

Sprite::Sprite(std::string texture, int x, int y, int width, int height, int clipX, int clipY, int clipWidth, int clipHeight)
{
    m_clip = new SDL_Rect();
    *m_clip = {clipX, clipY, clipWidth, clipHeight};
    m_rect = new SDL_Rect();
    *m_rect = {x, y, width, height};
    m_texture = texture;
}

Sprite::~Sprite()
{
    delete m_rect;
    if (m_clip != NULL)
        delete m_clip;
}

void Sprite::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderCopy(renderer, m_spriteSheet, m_clip, m_rect);
}

void Sprite::update()
{

}

void Sprite::renderManagerRegistered(RenderManager *renderManager)
{
    m_spriteSheet = renderManager->loadTexture(m_texture);
}
