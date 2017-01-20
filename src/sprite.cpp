#include "sprite.h"

using namespace std;


Sprite::Sprite(RenderManager *renderManager, string texture, float x, float y, float width, float height)
{
    m_renderManager = renderManager;
    m_texture = texture;
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;

    m_renderManager->loadTexture(m_texture);
}

Sprite::~Sprite()
{

}

void Sprite::render(SDL_Renderer *renderer)
{
    SDL_Rect fillRect = {m_x, m_y, m_width, m_height};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect); 
}

void Sprite::update()
{

}
