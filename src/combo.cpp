#include "combo.h"

#include <iostream>


using namespace std;


ComboRecognizer::ComboRecognizer(float timeout)
{
    m_timeout = timeout;
}

void ComboRecognizer::keyDown(SDL_Keycode code)
{
    addEvent(code);
}

void ComboRecognizer::keyUp(SDL_Keycode code)
{

}

void ComboRecognizer::addCombo(vector<SDL_Keycode> combo)
{
    m_combos.push_back(combo);
}

void ComboRecognizer::addEvent(SDL_Keycode event)
{
    m_events.push_back(event);
    m_currentTime = 0;
    std::cout << m_events.size() << " events" << std::endl;
    for (size_t i = 0; i < m_combos.size(); ++i)
    {
        if (checkCombo(i))
            std::cout << "combo recognized" << std::endl;
    }
}

void ComboRecognizer::update(float deltaTime)
{
    m_currentTime += deltaTime;
    if (m_currentTime > m_timeout)
        m_events.clear();
}

bool ComboRecognizer::checkCombo(size_t idx)
{
    if (m_events.size() > m_combos[idx].size())
        return false;

    for (size_t i = 0; i < m_combos[idx].size(); ++i)
    {
        if (m_combos[idx][i] != m_events[i])
            return false;
        if (i == m_combos[idx].size() - 1)
            return true;
    }
    return false;
}

