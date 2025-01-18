#ifndef ASSIGNPROFESSORTOCOURSE_HPP
#define ASSIGNPROFESSORTOCOURSE_HPP

#include <Forms/Form.hpp>

class Course;
class Professor;

class AssignProfessorToCourse : public Form
{
private:
    Course *_course;
    Professor *_professor;

public:
    AssignProfessorToCourse(Course *p_course, Professor *p_professor);
    void onExectute();
    ~AssignProfessorToCourse();
};

#endif
