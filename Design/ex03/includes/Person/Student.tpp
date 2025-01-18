#include <Person/Student.hpp>

template <typename... Args>
void Student::receive(const std::string &event, Args &&...args)
{
    std::cout << "Student " << _name << " received event: " << event << std::endl;
    (std::cout << ... << args) << std::endl;
}