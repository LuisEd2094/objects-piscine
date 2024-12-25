#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <algorithm>
#include <iostream>
#include <Vector2.hpp>
#include <fstream>
#include <Aux.hpp>
#include <cmath>

class Graph
{
public:
    Graph();
    Graph(const std::string &file);
    ~Graph();
    void addVector(float, float);
    void addLine(const Vector2 &a, const Vector2 &b);
    std::list<Vector2>::const_iterator begin() const;
    std::list<Vector2>::const_iterator end() const;
    Vector2 getSize() const;
    void printGraph();

private:
    std::list<Vector2> _vectors;
    Vector2            _size;
    int _max_x;
    int _max_y;
};

#endif