#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <Person/Staff.hpp>
class Professor : public Staff
{
private:
    Course *_currentCourse;
    Professor() : Staff("Professor") {}

public:
    void assignCourse(Course *p_course);
    void doClass();
    void closeCourse();
    Professor(std::string p_name) : Staff(p_name) {}
    ~Professor() = default;
};
    

#endif