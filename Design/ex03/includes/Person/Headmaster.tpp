#include <Person/Headmaster.hpp>


template <typename... Args, typename E>
void Headmaster::receive(E e, Args &&... args)
{
    Event event = static_cast<Event>(e);
    switch (event)
    {
    case Event::AssignProfessorToCourse:
        handleAssignProfessorToCourse(args...);
        break;
    
    default:
        break;
    }

}