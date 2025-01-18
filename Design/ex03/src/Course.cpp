#include <Course.hpp>
#include <Professor.hpp>

void Course::assign(Professor *p_professor)
{
    if (_responsable == nullptr && p_professor != nullptr && p_professor->getCourseType() == _course_type)
        _responsable = p_professor;
    else
        throw std::runtime_error("Professor is not available or course type is not the same");
}
void Course::subscribe(Student *p_student)
{
    if (_students.size() <= _maximumNumberOfStudent)
        _students.push_back(p_student);
    else
        throw std::runtime_error("Course is full");
}