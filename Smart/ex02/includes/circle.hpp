#ifndef CIRCLE_HPP
# define CIRCLE_HPP



# include <shape.hpp>
# include <cmath> // For M_M_PI



class circle: public shape
{
private:
    circle() {};
    std::size_t _radius;
public:
    circle(std::size_t);
    std::size_t calculateArea() const;
    std::size_t calculatePerimeter() const;
    ~circle();
};

circle::circle(std::size_t radius) : _radius(radius)
{
}

circle::~circle()
{
}

std::size_t circle::calculateArea() const
{
    return M_PI * _radius * _radius;
}

std::size_t circle::calculatePerimeter() const
{
    return M_PI * _radius * 2;
}

#endif