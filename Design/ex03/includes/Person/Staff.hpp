#ifndef STAFF_HPP
#define STAFF_HPP

#include <Person.hpp>

class Course;
class Form;
class Staff : public Person
{
private:
    Staff() : Person("Staff") {}
public:
    void sign(Form *p_form);
    Staff(std::string p_name) : Person(p_name) {}
    Staff(std::string p_name, Room *p_room) : Person(p_name, p_room) {}
};


#endif