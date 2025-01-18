#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <Person.hpp>
#include <Mediator.hpp>
#include <List.hpp>

class Course;
class Classroom;
class Room;

class Student : public Person, public Mediatee
{
private:
    List<Course *> _subscribedCourse;

public:
    Student(std::string p_name);
    Student(std::string p_name, Room *p_classroom);
    ~Student();
    void attendClass(Classroom *p_classroom);
    void exitClass();
    void graduate(Course *p_course);
    template <typename... Args>
    void receive(const std::string &event, Args &&...args);
};

#include <Person/Student.tpp>

#endif