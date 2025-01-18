#ifndef PROFESSOR_TPP
#define PROFESSOR_TPP
#include <Person/Professor.hpp>

template <typename... Args>
void Professor::receive(const std::string &event, Args &&...args)
{
    std::cout << "Professor " << _name << " received event: " << event << std::endl;
    (std::cout << ... << args) << std::endl;
}

#endif