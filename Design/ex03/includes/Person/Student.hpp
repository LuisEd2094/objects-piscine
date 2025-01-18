#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <Person.hpp>
#include <vector>

class Classroom;
class Course;
class Headmaster;
class Student : public Person, public Mediatee
{
private:
    std::vector<Course *> _subscribedCourse;

public:
    Student(std::string p_name) : Person(p_name), Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {};
    Student(std::string p_name, Room *p_classroom) : Person(p_name, p_classroom), Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {};
    void attendClass(Classroom *p_classroom);
    void exitClass();
    void graduate(Course *p_course);
    ~Student() {};
    template <typename... Args>
    void receive(const std::string &event, Args &&...args)
    {
        std::cout << "Student " << _name << " received event: " << event << std::endl;
        (std::cout << ... << args) << std::endl;
    }

};

#endif