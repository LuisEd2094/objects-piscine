#include <Person/Professor.hpp>
#include <Singleton.hpp>
#include <Headmaster.hpp>
#include <Course.hpp>

Professor::Professor(std::string p_name, CourseType course_type) : Staff(p_name),
                                                                   Mediatee(&Singleton<Headmaster>::getInstance()),
                                                                   _current_course(nullptr),
                                                                   _course_type(course_type)
{
    addToList(this);
}
Professor::~Professor() {};
void Professor::assignCourse(Course *p_course)
{
    _current_course = p_course;
};
void Professor::doClass()
{
    if (_current_course)
    {
        std::cout << "Professor " << _name << " is doing class for course " << std::endl;
    }
    else
    {
        // We cast it otherwise it calls the base class
        if (auto headmasterMediator = dynamic_cast<Headmaster *>(_mediator))
            headmasterMediator->receive(Event::AssignProfessorToCourse, this, _course_type);
    }
};
void Professor::closeCourse() {};

CourseType Professor::getCourseType()
{
    return _course_type;
}