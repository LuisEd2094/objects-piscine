#ifndef STUDENT_TPP
#define STUDENT_TPP
#include <Person/Student.hpp>

template <typename... Args>
void Student::receive(Event event, Args &&...args)
{
    std::cout << "Student " << _name << " received event: " << static_cast<int>(event) << std::endl;
    (std::cout << ... << args) << std::endl;
}

#endif