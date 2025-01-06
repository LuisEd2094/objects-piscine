#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <vector>

class Student;
class Professor;

class Course
{
private:
    std::string _name;
    Professor *_responsable;
    std::vector<Student *> _students;
    int _numberOfClassToGraduate;
    int _maximumNumberOfStudent;
    Course();
public:
    Course(std::string p_name);
    void assign(Professor *p_professor);
    void subscribe(Student *p_student);
};

#endif
