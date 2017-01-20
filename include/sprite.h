#ifndef H_SPRITE
#define H_SPRITE

#include "rendermanager.h"


class Sprite: public Renderable
{
private:
    RenderManager *m_renderManager;
    std::string m_texture;
    float       m_x, m_y;
    float       m_width, m_height;

public:
    Sprite(RenderManager *renderManager, std::string texture, float x, float y, float width, float height);
    ~Sprite();

    void update();
    void render(SDL_Renderer *renderer);
};

#endif
