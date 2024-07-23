#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include <Tool.hpp>


class Shovel: public Tool
{
    public:
        void use();
        Shovel();
        ~Shovel();
    private:

};

class ShovelFinder
{
    public:
        bool operator()(Tool *tool)
        {
            return dynamic_cast<Shovel *>(tool) != NULL;
        }
};

#endif