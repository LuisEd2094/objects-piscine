#include <Hammer.hpp>

Hammer::Hammer(): Tool()
{

}

Hammer::~Hammer()
{

}

void Hammer::use()
{
    std::cout << "I am Hammering!" << std::endl;
    Tool::numberOfUses++;
}