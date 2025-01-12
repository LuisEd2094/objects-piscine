#ifndef HEADMASTEROFFICE_HPP
#define HEADMASTEROFFICE_HPP

#include <Rooms/Room.hpp>
#include <Person/Headmaster.hpp>
#include <Person/Secretary.hpp>


class HeadmasterOffice : public Room
{
private:
public:
    HeadmasterOffice() : Room(std::type_index(typeid(Headmaster)), std::type_index(typeid(Secretary))) {};
};
#endif