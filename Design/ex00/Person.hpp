#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
#include "enums.hpp"

class Room;

class Person
{
private:
    std::string _name;
    Room *_currentRoom;

public:
    Person(std::string p_name);
    Room *room() { return (_currentRoom); }
};



#endif