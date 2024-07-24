#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP


# include <shape.hpp>


class triangle: public shape
{
private:
    triangle() {};
    std::size_t _base, _height, _side_a, _side_b;
public:
    triangle(std::size_t, std::size_t, std::size_t, std::size_t);
    std::size_t calculateArea() const;
    std::size_t calculatePerimeter() const;
    ~triangle();
};

triangle::triangle(std::size_t base, std::size_t side_a, std::size_t side_b, std::size_t height) : _base(base), _height(height), _side_a(side_a), _side_b(side_b)
{
}

triangle::~triangle()
{
}

std::size_t triangle::calculateArea() const
{
    return (_base * _height) / 2;
}

std::size_t triangle::calculatePerimeter() const
{
    return _base + _side_a + _side_b;
}

#endif