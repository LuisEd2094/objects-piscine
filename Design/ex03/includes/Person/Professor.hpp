#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <Person/Staff.hpp>
#include <Mediator.hpp>
#include <enums.hpp>

class Course;
class Professor : public Staff, public Mediatee
{
private:
    Course *_current_course;
    CourseType _course_type;

public:
    Professor(std::string p_name, CourseType course_type);
    ~Professor();
    void assignCourse(Course *p_course);
    void doClass();
    void closeCourse();

    CourseType getCourseType();

    template <typename... Args>
    void receive(Event event, Args &&...args);

    void handleRingBell();
};

#include <Person/Professor.tpp>
#endif