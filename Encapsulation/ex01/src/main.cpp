#include <Graph.hpp>
#include <PNGWriter.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        if (argc == 1)
        {
            Graph graph;
            graph.addVector(0, 1);
            graph.addVector(2, 2);
            graph.addVector(4, 2);
            graph.addVector(4, 2);
            graph.addLine(Vector2(0, 0), Vector2(2, 9));

            graph.printGraph();
            std::cout << "Size: " << graph.getSize() << std::endl;

            Graph graph2;
            graph2.addLine(Vector2(0, 0), Vector2(2, 9));
            graph2.printGraph();
            PNGWriter::writePNG("test.png", graph2.generateImage());
        }
        else if (argc == 2)
        {
            Graph graph(argv[1]);
            PNGWriter::writePNG("test.png", graph.generateImage());
            
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