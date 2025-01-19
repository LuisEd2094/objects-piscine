#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <vector>
#include <List.hpp>
#include <enums.hpp>
class Professor;
class Student;
class CourseList;

class Course
{
private:
    CourseType _course_type;
    Professor *_responsable;
    List<Student *> _students;
    size_t _numberOfClassToGraduate;
    size_t _maximumNumberOfStudent;
    bool _isFinished;

    Course();
    Course(CourseType );
    friend class NeedCourseCreationForm;

public:

    void assign(Professor *p_professor);
    void subscribe(Student *p_student);
    void setFinished(bool p_isFinished);

    CourseType getType();

    /**
     * @brief Get the student at the index
     */
    Student *operator[](size_t index);

    /**
     * @brief Get the size of the list of students
     */
    size_t size();
};

#endif
