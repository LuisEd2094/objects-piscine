#include <Person/Professor.hpp>
#include <Singleton.hpp>
#include <Headmaster.hpp>
#include <Course.hpp>

Professor::Professor(std::string p_name, CourseType course_type) : Staff(p_name),
                                                                   Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())),
                                                                   _course_type(course_type) {}
Professor::~Professor() {};
void Professor::assignCourse(Course *p_course)
{
    _current_course = p_course;
};
void Professor::doClass() {};
void Professor::closeCourse() {};

CourseType Professor::getCourseType()
{
    return _course_type;
}