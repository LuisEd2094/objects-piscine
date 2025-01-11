#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
#include <enums.hpp>

class Room;

class Person
{
protected:
    std::string _name;
    Room *_currentRoom;
    Person(std::string p_name) : _name(p_name), _currentRoom(nullptr) {};
public:
    Room *room() { return (_currentRoom); }
};

#endif