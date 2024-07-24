#ifndef SHAPE_HPP
# define SHAPE_HPP

#include <cstdlib>

class shape
{
protected:
    shape();
public:
    virtual std::size_t calculateArea() const = 0;
    virtual std::size_t calculatePerimeter() const = 0;
    ~shape();
};

shape::shape()
{
}

shape::~shape()
{
}

#endif