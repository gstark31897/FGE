#include "event.h"


size_t EventManager::createEvent()
{
    return counter++;
}

void EventManager::registerListener(size_t event, void(*function)())
{
    m_listeners[event].push_back(function);
}

void EventManager::emitEvent(size_t event)
{
    for (std::vector<void (*)()>::iterator it = m_listeners[event].begin(); it != m_listeners[event].end(); ++it)
    {
        (*it)();
    }
}
