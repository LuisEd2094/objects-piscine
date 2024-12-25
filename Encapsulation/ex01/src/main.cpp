#include <Graph.hpp>
#include <iostream>


/* Vector2 go (y,x) to make it easier to print later*/
int main(int argc, char **argv)
{
    try{
        if (argc == 1)
        {
            Graph graph;
            graph.addVector(0, 0);
            graph.addVector(2, 2);
            graph.addVector(4, 2);
            graph.addVector(4, 2);
            graph.addLine(Vector2(0, 0), Vector2(2, 9));


            graph.printGraph();
            std::cout << "Size: " << graph.getSize() << std::endl;

            Graph graph2;
            graph2.addLine(Vector2(0, 0), Vector2(2, 9));
            graph2.printGraph();
        }
        else if (argc == 2)
        {
            Graph graph(argv[1]);
            graph.printGraph();
            std::cout << "Size: " << graph.getSize() << std::endl;
        }
        else
        {
            std::cerr << "Usage: ./graph [file]" << std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}