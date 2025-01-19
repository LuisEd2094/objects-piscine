#include <Course.hpp>
#include <Professor.hpp>
#include <Lists/CourseList.hpp>
#include <enums.hpp>
#include <List.hpp>
#include <enums.hpp>

Course::Course() : _course_type(CourseType::NONE),
                   _responsable(nullptr),
                   _numberOfClassToGraduate(0),
                   _maximumNumberOfStudent(30),
                   _isFinished(false)
{
    CourseList courseList;
    courseList.push_back(this);
};
Course::Course(CourseType p_course_type) : _course_type(p_course_type),
                                           _responsable(nullptr),
                                           _numberOfClassToGraduate(0),
                                           _maximumNumberOfStudent(30),
                                           _isFinished(false)
{
    CourseList courseList;
    courseList.push_back(this);
};

void Course::assign(Professor *p_professor)
{
    if (_responsable == nullptr && p_professor != nullptr && p_professor->getCourseType() == _course_type)
    {
        _responsable = p_professor;
        p_professor->assignCourse(this);
    }
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

void Course::setFinished(bool p_isFinished)
{
    _isFinished = p_isFinished;
}
CourseType Course::getType()
{
    return _course_type;
}

/**
 * @brief Get the student at the index
 */
Student *Course::operator[](size_t index)
{
    return _students[index];
}

size_t Course::size()
{
    return _students.size();
}
