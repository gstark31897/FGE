#ifndef H_KEYBOARD
#define H_KEYBOARD

#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include <iostream>

#include "keyboard.h"


class KeyListener
{
public:
    virtual void keyDown(SDL_Keycode code) {};
    virtual void keyUp(SDL_Keycode code) {};
};


class KeyboardManager
{
private:
    std::map<SDL_Keycode, bool> m_keys;
    std::vector<KeyListener*> m_listeners;

public:
    void keyDown(SDL_Keycode key);
    void keyUp(SDL_Keycode key);

    void registerKeyListener(KeyListener *listener);
};

#endif
