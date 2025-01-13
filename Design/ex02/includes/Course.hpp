#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <vector>
#include <List.hpp>

class Student;
class Professor;

class Course
{
private:
    std::string _name;
    Professor *_responsable;
    List<Student *> _students;
    size_t _numberOfClassToGraduate;
    size_t _maximumNumberOfStudent;
    bool _isFinished;

    Course();

public:
    Course(std::string p_name) : _name(p_name), _responsable(nullptr), _numberOfClassToGraduate(0), _maximumNumberOfStudent(30), _isFinished(false) {};
    void assign(Professor *p_professor)
    {
        if (_responsable == nullptr)
            _responsable = p_professor;
    }
    void subscribe(Student *p_student)
    {
        if (_students.size() <= _maximumNumberOfStudent)
            _students.push_back(p_student);
    }
    void setFinished(bool p_isFinished) { _isFinished = p_isFinished; }

    /**
     * @brief Get the student at the index
     */
    Student *operator[](size_t index) { return _students[index]; }

    /**
     * @brief Get the size of the list of students
     */
    size_t size() { return _students.size(); }
    std::string getName() { return _name; }
};

#endif
