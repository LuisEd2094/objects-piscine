#include <shape.hpp>
#include <rectangle.hpp>
#include <iostream>


void seeArea (const shape& shape)
{
    std::cout << shape.calculateArea() << std::endl;
}

void seePerimeter (const shape& shape)
{
        std::cout << shape.calculatePerimeter() << std::endl;
}

int main(void)
{
    rectangle rect(10, 10);
    seeArea(rect);
    seePerimeter(rect);
}