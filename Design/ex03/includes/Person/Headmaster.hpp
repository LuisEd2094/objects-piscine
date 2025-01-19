#ifndef HEADMASTER_HPP
#define HEADMASTER_HPP

#include <Person/Staff.hpp>
#include <Mediator.hpp>
#include <enums.hpp>

template <typename T>
class Singleton;
class From;
class Course;
class Professor;
class Headmaster : public Staff, public Mediator
{
private:
    List<Form *> _formToValidate;
    friend class Singleton<Headmaster>;
    Headmaster();
    void assignProfessorToCourse(Professor *professor, Course *course);
    void createCourse(CourseType course_type);

public:
    void receiveForm(Form *p_form);
    void signForm(Form *p_form);
    void signForm();
    void executeForm(Form *p_form);
    void executeForm();
    void handleAssignProfessorToCourse(Professor *professor, CourseType course_type);

    template <typename... Args, typename E>
    void receive(E, Args &&...);
    ~Headmaster();
};

#include <Person/Headmaster.tpp>

#endif