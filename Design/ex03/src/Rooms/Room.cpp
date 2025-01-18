#include <Rooms/Room.hpp>
#include <Person/Person.hpp>
long long Room::ID = 0;

Room::Room()
{
    ++Room::ID;
};
Room::~Room() {};

bool Room::canEnter(Person *p_person)
{
    for (auto &type : _allowedOccupants)
    {
        if (std::type_index(typeid(*p_person)) == type)
        {
            return true;
        }
    }
    return false;
};
void Room::enter(Person *p_person)
{
    if (canEnter(p_person))
    {
        _occupants.push_back(p_person);
    }
};
void Room::exit(Person *p_person)
{
    (void)p_person;
};

void Room::printOccupant() {

};