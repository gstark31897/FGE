#ifndef EVENT_H
#define EVENT_H

#include <map>
#include <vector>


class EventManager
{
private:
    std::map<size_t, std::vector<void (*)()>> m_listeners;
    size_t counter = 0;

public:
    size_t createEvent();
    void registerListener(size_t event, void(*function)());
    void emitEvent(size_t event);
};

#endif
