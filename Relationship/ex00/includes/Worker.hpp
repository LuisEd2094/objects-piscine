#ifndef WORKER_HPP
#define WORKER_HPP

#include <list>
#include <cstddef>
#include <algorithm>

typedef struct Position
{
    int _x;
    int _y;
    int _z;
    Position(int x, int y, int z) : _x(x), _y(y), _z(z) {};
} Position;

typedef struct Statistic
{
    int _level;
    int _exp;
    Statistic(int level, int exp) : _level(level), _exp(exp) {};
} Statistic;

/* Subject asks for coordonnee [sic] and stat to be a Composition of worker,
    meaning they are required and present at the moment of object creation

    */

class Tool;
class Hammer;
class Shovel;
class Workshop;

template <typename ToolType>
class ToolFinder
{
public:
    bool operator()(Tool *tool) const
    {
        return dynamic_cast<ToolType *>(tool) != NULL;
    }
};

class Worker
{
public:
    Worker();
    ~Worker();
    void resetTool(Tool *);
    void setTool(Tool *);
    void addWorkshop(Workshop *);
    void removeWorkShop(Workshop *);

    void work();

    template <typename ToolType>
    ToolType *GetTool()
    {
        typename std::list<Tool *>::iterator it = std::find_if(_tools.begin(), _tools.end(), ToolFinder<ToolType>());
        if (it != _tools.end())
        {
            return dynamic_cast<ToolType *>(*it);
        }
        return NULL;
    }
    Position coordonnee;
    Statistic stat;
    std::list<Tool *> _tools;
    std::list<Workshop *> _workshops;

private:
};

class WorkerMatcher
{
public:
    WorkerMatcher(Worker *worker) : workerToMatch(worker) {}

    bool operator()(Worker *w) const
    {
        return w == workerToMatch;
    }

private:
    Worker *workerToMatch;
};

#endif