#include <Person/Headmaster.hpp>
#include <Person/Professor.hpp>
#include <Person/Secretary.hpp>
#include <Forms/FormCommander.hpp>
#include <Lists/CourseList.hpp>
#include <Course.hpp>

Headmaster::Headmaster() : Staff("Headmaster")
{
    addToList(this);
}
Headmaster::~Headmaster() {};

void Headmaster::receiveForm(Form *p_form)
{
    _formToValidate.push_back(p_form);
}

void Headmaster::signForm()
{
    for (auto form : _formToValidate)
    {
        FormCommander::FormSigner::sign(*form);
    }
}

void Headmaster::executeForm()
{
    for (auto form : _formToValidate)
    {
        FormCommander::FormExecutor::execute(*form);
    }
}

void Headmaster::signForm(Form *p_form)
{
    FormCommander::FormSigner::sign(*p_form);
}

void Headmaster::executeForm(Form *p_form)
{
    FormCommander::FormExecutor::execute(*p_form);
}

void Headmaster::createCourse(CourseType course_type)
{
    Secretary secretary = Singleton<Secretary>::getInstance();
    std::cout << &secretary << std::endl;
    Form *form = secretary.createForm(FormType::NeedCourseCreation, course_type);
    signForm(form);
    executeForm(form);
    delete form;
}

void Headmaster::assignProfessorToCourse(Professor *professor, Course *course)
{

    Secretary secretary = Singleton<Secretary>::getInstance();

    std::cout << &secretary << std::endl;
    Form *form = secretary.createForm(FormType::AssignProfessorToCourse, course, professor);
    signForm(form);
    executeForm(form);
    delete form;
}

void Headmaster::handleAssignProfessorToCourse(Professor *professor, CourseType course_type)
{
    CourseList courseList;
    Course *course = courseList.getCourse(course_type);

    if (course)
    {
        assignProfessorToCourse(professor, course);
    }
    else
    {
        createCourse(course_type);
        course = courseList.getCourse(course_type);
        assignProfessorToCourse(professor, course);
    }
}
