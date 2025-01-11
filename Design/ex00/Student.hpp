#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <Person.hpp>
#include <vector>

class Classroom;
class Course;
class Student : public Person
{
private:
    std::vector<Course *> _subscribedCourse;

public:
    Student(std::string p_name): Person(p_name) {};
    Student(std::string p_name, Room *p_classroom): Person(p_name, p_classroom) {};
    void attendClass(Classroom *p_classroom);
    void exitClass();
    void graduate(Course *p_course);
};

#endif 