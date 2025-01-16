#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
#include <enums.hpp>
#include <Singleton.hpp>
#include <Mediator.hpp>
class Room;

class Person
{   
protected:
    std::string _name;
    Room *_currentRoom;

    Person(std::string p_name) : _name(p_name), _currentRoom(nullptr) {};
    Person(std::string p_name, Room *p_room) : _name(p_name), _currentRoom(p_room) {};
public:
    Room *room() { return (_currentRoom); }
    std::string getName() const { return _name; };
    void enterRoom(Room *p_room) { _currentRoom = p_room; };
    // If a Class is not meant to be inherited from, 
    // it should have a virtual destructor to ensure polymorphic class
    virtual ~Person() = 0; 
};

#endif