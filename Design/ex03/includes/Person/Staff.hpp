#ifndef STAFF_HPP
#define STAFF_HPP

#include <Person.hpp>

class Form;
class Room;

class Staff : public Person
{
private:
    Staff();
protected:
    void addToList(Staff *);
public:
    Staff(std::string p_name);
    Staff(std::string p_name, Room *p_room);
    ~Staff();

};


#endif