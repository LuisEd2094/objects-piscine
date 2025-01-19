#ifndef PROFESSOR_TPP
#define PROFESSOR_TPP
#include <Person/Professor.hpp>

template <typename... Args>
void Professor::receive(Event event, Args &&...args)
{
    switch (event)
    {
    case Event::RingBell:
        doClass();
        break;
    
    default:
        std::cerr << "Professor " << _name << " received unknown event: " << static_cast<int>(event) << std::endl;
        break;
    }
}

#endif