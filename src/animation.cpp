#include "animation.h"


Frame::Frame(SDL_Texture *texture, int x, int y, int width, int height, int clipX, int clipY, int clipWidth, int clipHeight)
{
    m_texture = texture;

    m_rect = new SDL_Rect();
    *m_rect = {x, y, width, height};

    m_clip = new SDL_Rect();
    *m_clip = {clipX, clipY, clipWidth, clipHeight};
}

Frame::~Frame()
{
    delete m_rect;
    delete m_clip;
}

void Frame::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderCopy(renderer, m_texture, m_clip, m_rect);
}


Animation::Animation(float frameTime)
{
    m_frameTime = frameTime;
    m_currentTime = 0.0;
}

Animation::~Animation()
{
    for (std::vector<Frame*>::iterator it = m_frames.begin(); it != m_frames.end(); ++it)
    {
        delete *it;
    }
}

void Animation::update(float deltaTime)
{
    m_currentTime += deltaTime;
    while (m_currentTime >= m_frameTime * m_frames.size())
    {
        m_currentTime -= m_frameTime *m_frames.size();
    }
}

void Animation::render(SDL_Renderer *renderer)
{
    m_frames[(int)(m_currentTime/m_frameTime)]->render(renderer);
}

void Animation::renderManagerRegistered(RenderManager *renderManager)
{
    m_renderManager = renderManager;
}

void Animation::addFrame(std::string spriteSheet, int x, int y, int width, int height, int clipX, int clipY, int clipWidth, int clipHeight)
{
    SDL_Texture *texture = m_renderManager->loadTexture(spriteSheet);
    m_frames.push_back(new Frame(texture, x, y, width, height, clipX, clipY, clipWidth, clipHeight));
}

