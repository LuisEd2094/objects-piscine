#include <Forms/AssignProfessorToCourse.hpp>
#include <Course.hpp>
#include <Person/Professor.hpp>

AssignProfessorToCourse::AssignProfessorToCourse(Course *p_course, Professor *p_professor) : Form(FormType::AssignProffesorToCourse),
                                                                                             _course(p_course),
                                                                                             _professor(p_professor) {};
void AssignProfessorToCourse::onExectute()
{
    _course->assign(_professor);
    std::cout << "Assign form executed" << std::endl;
};
AssignProfessorToCourse::~AssignProfessorToCourse() {};