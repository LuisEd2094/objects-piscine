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
    std::list<Tool *>::iterator it = _tool.begin();

    for (; it != _tool.end(); ++it)
        (*it)->resetWorker();
}

void Worker::resetTool(Tool * tool)
{
    _tool.remove_if(ToolMatcher(tool));
}

/**
 * @brief Resets _tool and tool to have no worker assigned to them. Then sets tool to be used by this and _tool = tool
 * 
 * @param tool new tool to be used by worker
 */
void Worker::setTool(Tool* tool)
{
    std::list<Tool *>::iterator it = std::find(_tool.begin(), _tool.end(), tool);
    
    /*If not found then we set it*/
    if (it == _tool.end())
    {
        _tool.push_back(tool);
        tool->setWorker(this);
    }
}

/**
 * @brief Get the Tool Shovel object, first on the list of tools
 * 
 * @return Shovel* 
 */
Shovel *Worker::GetToolShovel()
{
    std::list<Tool *>::iterator it = std::find_if(_tool.begin(), _tool.end(), ShovelFinder());

    if (it != _tool.end())
        return dynamic_cast<Shovel *>(*it);
    return NULL;
}
/**
 * @brief Get the Tool Hammer object, first on the list of tools
 * 
 * @return Hammer* 
 */
Hammer *Worker::GetToolHammer()
{
    std::list<Tool *>::iterator it = std::find_if(_tool.begin(), _tool.end(), HammerFinder());

    if (it != _tool.end())
        return dynamic_cast<Hammer *>(*it);
    return NULL;
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