#include "keyboard.h"

using namespace std;


void KeyboardManager::keyDown(SDL_Keycode code)
{
    m_keys[code] = true;
    for (vector<KeyListener*>::iterator it = m_listeners.begin(); it != m_listeners.end(); ++it)
    {
        (*it)->keyDown(code);
    }
}

void KeyboardManager::keyUp(SDL_Keycode code)
{
    m_keys[code] = false;
    for (vector<KeyListener*>::iterator it = m_listeners.begin(); it != m_listeners.end(); ++it)
    {
        (*it)->keyUp(code);
    }
}

void KeyboardManager::registerKeyListener(KeyListener *listener)
{
    m_listeners.push_back(listener);
}
