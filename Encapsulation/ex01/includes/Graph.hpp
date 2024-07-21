#ifndef GRAPH_HPP
# define GRAPH_HPP

# include <Vector2.hpp> 
# include <list>
# include <algorithm>
# include <iostream>

class Graph
{
    public:
        Graph();
        ~Graph();
        void addVector(float, float);
        std::list<Vector2>::const_iterator  begin() const;
        std::list<Vector2>::const_iterator  end() const;
        std::size_t                         getSize() const;
        void                                printGraph();

    private:
        std::list<Vector2>  _vectors;
        std::size_t         _size;
        int                 _max_x;
        int                 _max_y;


};

#endif