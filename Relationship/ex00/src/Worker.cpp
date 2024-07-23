#include <Worker.hpp>
#include <Tool.hpp>
#include <Workshop.hpp>


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
    std::list<Tool *>::iterator it = std::find(_tool.begin(), _tool.end(), tool);

    if (it != _tool.end())
        _tool.erase(it);
}

/**
 * @brief Resets _tool and tool to have no worker assigned to them. Then sets tool to be used by this and _tool = tool
 * 
 * @param tool new tool to be used by worker
 */
void Worker::setTool(Tool * tool)
{
    std::list<Tool *>::iterator it = std::find(_tool.begin(), _tool.end(), tool);
    
    /*If not found then we set it*/
    if (it == _tool.end())
    {
        _tool.push_back(tool);
        tool->setWorker(this);
    }
}