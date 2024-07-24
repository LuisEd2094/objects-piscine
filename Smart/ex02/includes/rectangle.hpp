#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include <shape.hpp>


class rectangle : public shape
{
private:
    std::size_t _width;
    std::size_t _height;
public:
    rectangle(std::size_t, std::size_t);
    ~rectangle();
    std::size_t calculateArea() const;
    std::size_t calculatePerimeter() const;
 
};

rectangle::rectangle(std::size_t width, std::size_t height) : _width(width), _height(height)
{
    
}

rectangle::~rectangle()
{
}

std::size_t rectangle::calculateArea() const
{
    return _width * _height;
}
std::size_t rectangle::calculatePerimeter() const
{
    return (_width + _height) * 2;
}
 



#endif