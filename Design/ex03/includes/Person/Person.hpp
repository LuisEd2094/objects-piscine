#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
class Room;
class Person
{   
protected:
    std::string _name;
    Room *_currentRoom;

    Person(std::string p_name);
    Person(std::string p_name, Room *p_room);
public:
    Room *room();
    std::string getName() const ;
    void enterRoom(Room *p_room);
    // If a Class is not meant to be inherited from, 
    // it should have a virtual destructor to ensure polymorphic class
    virtual ~Person() = 0; 
};

#endif