#include <Person/Person.hpp>

Person::~Person() {}

Person::Person(std::string p_name) : _name(p_name),
                                     _currentRoom(nullptr) {};
Person::Person(std::string p_name, Room *p_room) : _name(p_name),
                                                   _currentRoom(p_room) {};
Room *Person::room()
{
    return (_currentRoom);
}
std::string Person::getName() const
{
    return _name;
};
void Person::enterRoom(Room *p_room)
{
    _currentRoom = p_room;
};