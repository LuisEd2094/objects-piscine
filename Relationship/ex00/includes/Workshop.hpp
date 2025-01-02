#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <algorithm>

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
    Shovel *_needs_shovel;
    Hammer *_needs_hammer;

private:
    Workshop() {};
};

class WorkshopMatcher
{
public:
    WorkshopMatcher(Workshop *w) : workShopToMatch(w) {}

    bool operator()(Workshop *w) const
    {
        return w == workShopToMatch;
    }

private:
    Workshop *workShopToMatch;
};

class WorkshopRemover
{
private:
    Worker *_worker;

public:
    explicit WorkshopRemover(Worker *worker) : _worker(worker) {}

    bool operator()(Workshop *workshop) const
    {
        if (!workshop->canSignUp(_worker))
        {
            workshop->signOff(_worker);
            return true;
        }
        return false;
    }
};

#endif