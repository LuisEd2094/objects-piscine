#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <Person/Staff.hpp>
#include <Person/Headmaster.hpp>
class Course;
class Professor : public Staff, public Mediatee
{
private:
    Course *_current_course;
    CourseType _course_type;
    Professor() : Staff("Professor"), Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {}

public:
    void assignCourse(Course *p_course);
    void doClass();
    void closeCourse();
    Professor(std::string p_name, CourseType course_type) : Staff(p_name),
                                    Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())),
                                    _course_type(course_type) {}
    ~Professor() {};

    CourseType getCourseType() { return _course_type; }
    template <typename... Args>
    void receive(const std::string &event, Args &&...args)
    {
        std::cout << "Professor " << _name << " received event: " << event << std::endl;
        (std::cout << ... << args) << std::endl;
    }
};

#endif