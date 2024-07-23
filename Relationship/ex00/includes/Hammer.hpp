#ifndef HAMMER_HPP
# define HAMMER_HPP

# include <Tool.hpp>

class Hammer: public Tool
{
    public:
        void use();
        Hammer();
        ~Hammer();
    private:

};

class HammerFinder
{
    public:
        bool operator()(Tool *tool)
        {
            return dynamic_cast<Hammer *>(tool) != NULL;
        }
};

#endif