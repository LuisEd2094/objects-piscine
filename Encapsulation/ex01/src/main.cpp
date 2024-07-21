#include <Graph.hpp>
#include <iostream>


/* Vector2 go (y,x) to make it easier to print later*/
int main(void)
{
    Graph graph;

    graph.addVector(0, 0);
    graph.addVector(2, 2);
    graph.addVector(4, 2);
    graph.addVector(2, 4);   
    graph.printGraph();
}