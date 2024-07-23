#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP


# include <algorithm>


class Tool;
class Shovel;
class Hammer;
class Worker;

class Workshop
{
    public:
        Workshop(Tool *);
        ~Workshop();

        void executeWorkDay();
        void signUp(Worker *);
        bool canSignUp(Worker *);
        void signOff(Worker *);

        std::list<Worker *> _students;
        Shovel *            _needs_shovel;
        Hammer *            _needs_hammer;
    private:
        Workshop() {};

};


#endif