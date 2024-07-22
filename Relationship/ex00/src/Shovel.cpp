#include <Shovel.hpp>

Shovel::Shovel(): Tool()
{

}

Shovel::~Shovel()
{

}

void Shovel::use()
{
    std::cout << "I am shoveling!" << std::endl;
    Tool::numberOfUses++;
}