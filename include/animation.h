#ifndef H_ANIMATION
#define H_ANIMATION


#include "sprite.h"


class Frame
{
private:
    SDL_Texture *m_texture;
    SDL_Rect *m_rect;
    SDL_Rect *m_clip;

public:
    Frame(SDL_Texture *texture, int x, int y, int width, int height, int clipX, int clipY, int clipWidth, int clipHeight);
    ~Frame();

    void render(SDL_Renderer *renderer);
};


class Animation: public Renderable
{
private:
    std::vector<Frame*> m_frames;
    float m_frameTime;
    float m_currentTime;
    RenderManager *m_renderManager;

public:
    Animation(float frameTime);
    ~Animation();

    void update(float deltaTime);
    void render(SDL_Renderer *renderer);

    void renderManagerRegistered(RenderManager *renderManager);

    void addFrame(std::string spriteSheet, int x, int y, int width, int height, int clipX, int clipY, int clipWidth, int clipHeight);
};

#endif
