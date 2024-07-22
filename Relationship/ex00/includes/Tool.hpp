#ifndef TOOL_HPP
# define TOOL_HPP

# include <cstddef>
# include <iostream>
# include <Worker.hpp>
class Worker;

class Tool
{
    public:
        virtual void use () = 0;
        Tool() : numberOfUses(0), worker(NULL){};
        ~Tool() {resetWorker();};
        void resetWorker() {if (worker) worker->resetTool(); worker = NULL;}
        void setWorker(Worker *w) {worker = w;}; 

        
        std::size_t numberOfUses;
        Worker *    worker;
    private:

};




#endif