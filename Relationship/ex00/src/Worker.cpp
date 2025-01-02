#include <Worker.hpp>
#include <Tool.hpp>
#include <Workshop.hpp>
#include <Shovel.hpp>
#include <Hammer.hpp>

Worker::Worker(): coordonnee(0,0,0), stat(0,0)
{

}

Worker::~Worker()
{
    std::list<Tool *>::iterator it = _tools.begin();
    std::list<Workshop *>::iterator it2 = _workshops.begin();

    for (; it != _tools.end(); ++it)
    {
        (*it)->resetWorker();
    }
    for (; it2 != _workshops.end(); ++it2)
    {
        (*it2)->signOff(this);
    }  

}

void Worker::removeWorkShop(Workshop *workshop)
{
    _workshops.remove_if(WorkshopMatcher(workshop));

}
/**
 * @brief Removes tool if worker has it. Removes itself from _workshops that need said tool
 * 
 * @param tool 
 */
void Worker::resetTool(Tool * tool)
{
    _tools.remove_if(ToolMatcher(tool));
    _workshops.remove_if(WorkshopRemover(this));
}

/**
 * @brief Resets _tools and tool to have no worker assigned to them. Then sets tool to be used by this and _tools = tool
 * 
 * @param tool new tool to be used by worker
 */
void Worker::setTool(Tool* tool)
{
    std::list<Tool *>::iterator it = std::find(_tools.begin(), _tools.end(), tool);
    
    /*If not found then we set it*/
    if (it == _tools.end())
    {
        _tools.push_back(tool);
        tool->setWorker(this);
    }
}

void Worker::addWorkshop(Workshop *workshop)
{
    std::list<Workshop *>::iterator it = std::find(_workshops.begin(), _workshops.end(), workshop);

    if (it == _workshops.end())
    {
        if (workshop->canSignUp(this))
        {
            _workshops.push_back(workshop);
            workshop->signUp(this);
        }
    }
}

void Worker::work()
{
    if (_workshops.size() > 0)
        std::cout << "I am working lala" << std::endl;
}