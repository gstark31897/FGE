#ifndef H_COMBO
#define H_COMBO


#include <SDL2/SDL.h>
#include <vector>

#include "keyboard.h"


class ComboRecognizer: public KeyListener
{
private:
    std::vector<std::vector<SDL_Keycode>> m_combos;
    std::vector<SDL_Keycode> m_events;
    float m_timeout;
    float m_currentTime;
    bool checkCombo(size_t idx);

public:
    ComboRecognizer(float timeout);
    ~ComboRecognizer() {};

    void keyDown(SDL_Keycode);
    void keyUp(SDL_Keycode);

    void addCombo(std::vector<SDL_Keycode> combo);
    void addEvent(SDL_Keycode event);
    void update(float deltaTime);
};

#endif
