#ifndef WORKER_HPP
# define WORKER_HPP

# include <list>
# include <cstddef>
# include <algorithm>


typedef struct Position
{
    int _x;
    int _y;
    int _z;
    Position(int x, int y, int z) : _x(x), _y(y), _z(z) {};
}Position;

typedef struct Statistic
{
    int _level;
    int _exp;
    Statistic(int level, int exp) : _level(level), _exp(exp) {};
}Statistic;



/* Subject asks for coordonnee [sic] and stat to be a Composition of worker,
    meaning they are required and present at the moment of object creation

    */

class Tool;
class Hammer;
class Shovel;
class Workshop;
class Worker
{
    public:
        Worker();
        ~Worker();
        void resetTool(Tool *);
        void setTool(Tool *);

        /*Hammer * GetToolHammer();
        Shovel * GetToolShovel();*/


        Position                coordonnee;
        Statistic               stat;
        std::list<Tool *>       _tool;
        std::list<Workshop>     _workshops; 

    private:


};

#endif