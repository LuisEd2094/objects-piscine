#ifndef TOOL_HPP
# define TOOL_HPP

# include <cstddef>
# include <iostream>
# include <Worker.hpp>
class Worker;

class Tool
{
    public:
        virtual void use() = 0;
        Tool() : numberOfUses(0), worker(NULL){};
        virtual ~Tool() {if (worker) {worker->resetTool(this);}};

        void resetWorker() {worker = NULL;}
        void setWorker(Worker *w) {if (worker) {worker->resetTool(this);} worker = w;}; 

        
        std::size_t numberOfUses;
        Worker *    worker;
    private:

};


// Functor to check if a Tool* matches the given Tool*

class ToolMatcher
{
    public: 
        ToolMatcher(Tool * tool) : toolToMatch(tool) {}
        
        bool operator()(Tool* t) const 
        {
            return t == toolToMatch;
        }

    private:
        Tool * toolToMatch;
};




#endif