#ifndef H_COMBO
#define H_COMBO


#include <SDL2/SDL.h>
#include <vector>


class ComboRecognizer
{
private:
    std::vector<std::vector<SDL_KeyboardEvent>> m_combos;
    std::vector<SDL_KeyboardEvent> m_events;
    float m_timeout;
    float m_currentTime;

public:
    ComboRecognizer(float timeout);
    ~ComboRecognizer();

    void addCombo(std::vector<SDL_KeyboardEvent> combo);
    void addEvent(SDL_KeyboardEvent event);
    void update(float deltaTime);
};

#endif
