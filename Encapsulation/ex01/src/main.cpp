#include <Graph.hpp>
#include <iostream>


/* Vector2 go (y,x) to make it easier to print later*/
int main(void)
{
    try{
        Graph graph;
        graph.addVector(0, 0);
        graph.addVector(2, 2);
        graph.addVector(4, 2);
        graph.addVector(2, 4);
        graph.printGraph();
        std::cout << "Size: " << graph.getSize() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}