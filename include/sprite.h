#ifndef H_SPRITE
#define H_SPRITE

#include "rendermanager.h"


class Sprite: public Renderable
{
private:
    std::string    m_texture;
    SDL_Rect      *m_rect = NULL;
    SDL_Rect      *m_clip = NULL;
    SDL_Texture   *m_spriteSheet = NULL;

public:
    Sprite(std::string texture, int x, int y, int width, int height);
    Sprite(std::string texture, int x, int y, int width, int height, int clipX, int clipY, int clipWidth, int clipHeight);
    ~Sprite();

    void update();
    void render(SDL_Renderer *renderer);

    void renderManagerRegistered(RenderManager *renderManager);
};

#endif
