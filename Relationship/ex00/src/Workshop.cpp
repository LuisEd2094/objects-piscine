#include <Tool.hpp>
#include <Worker.hpp>
#include <Workshop.hpp>
#include <Shovel.hpp>
#include <Hammer.hpp>

Workshop::Workshop(Tool *tool)
{
    _needs_shovel = dynamic_cast<Shovel *>(tool);
    _needs_hammer = dynamic_cast<Hammer *>(tool);
}

Workshop::~Workshop()
{
    std::list<Worker *>::iterator it = _students.begin();
    for (; it != _students.end(); ++it)
    {
        (*it)->removeWorkShop(this);
    }  

}

void Workshop::executeWorkDay()
{
    for (std::list<Worker *>::iterator it = _students.begin() ; it != _students.end(); ++it)
    {
        (*it)->work();
    }
}

void Workshop::signOff(Worker* worker)
{
    _students.remove_if(WorkerMatcher(worker));
}

bool Workshop::canSignUp(Worker * worker)
{
    if (_needs_shovel && worker->GetToolShovel())
        return true;
    else if (_needs_hammer && worker->GetToolHammer())
        return true;
    return false;
}

void Workshop::signUp(Worker * worker)
{
    std::list<Worker *>::iterator it = std::find(_students.begin(), _students.end(), worker);

    if (it == _students.end())
    {
        if (canSignUp(worker))
        {
            _students.push_back(worker);
            worker->addWorkshop(this);
        }

    }
}