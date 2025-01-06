#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
#include "enums.hpp"

class Room;
class Form;
class Course;
class Classroom;

class Person
{
private:
    std::string _name;
    Room *_currentRoom;

public:
    Person(std::string p_name);
    Room *room() { return (_currentRoom); }
};


class Student : public Person
{
private:
    std::vector<Course *> _subscribedCourse;

public:
    void attendClass(Classroom *p_classroom);
    void exitClass();
    void graduate(Course *p_course);
};
#endif