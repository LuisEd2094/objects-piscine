#include <Worker.hpp>
#include <Tool.hpp>
#include <Workshop.hpp>


Worker::Worker(): coordonnee(0,0,0), stat(0,0)
{

}

Worker::~Worker()
{
    if (_tool)
        _tool->resetWorker();

}

void Worker::resetTool()
{
    _tool = NULL;
}

/**
 * @brief Resets _tool and tool to have no worker assigned to them. Then sets tool to be used by this and _tool = tool
 * 
 * @param tool new tool to be used by worker
 */
void Worker::setTool(Tool * tool)
{
    std::list<Tool *>::iterator it = std::find(_tool.begin(), _tool.end(), tool);
    /*
    if (_tool)
        _tool->resetWorker();
    tool->resetWorker();
    tool->setWorker(this);
    _tool = tool;*/
}