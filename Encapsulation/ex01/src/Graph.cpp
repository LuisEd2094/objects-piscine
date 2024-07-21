#include <Graph.hpp>

Graph::Graph():
        _size(0),
        _max_x(0),
        _max_y(0)
{

}
Graph::~Graph(){}

bool compareVectors(Vector2 a, Vector2 b)
{
    if (a.points[0] == b.points[0])
        return a.points[1] < b.points[1];
    return a.points[0] > b.points[0];
}


void Graph::addVector(float y, float x)
{
    _vectors.push_back(Vector2(y,x));
    _max_x = std::max(_max_x, (int)x);
    _max_y = std::max(_max_y, (int)y);
    _size = _vectors.size();
    _vectors.sort(compareVectors);
}
 
std::size_t Graph::getSize() const
{
    return _size;
}

void Graph::printGraph()
{
    std::list<Vector2>::const_iterator it = _vectors.begin();
    std::list<Vector2>::const_iterator it2 = _vectors.end();
    for (int i = _max_y + 1; i >= 0 ; --i)
    {
        std::cout << i << ' ';
        for (int j = 0; j <= _max_x + 1; ++j)
        {
            if (it != it2 && i == it->points[0] && j == it->points[1])
            {
                std::cout << 'X';
                it++;
            }
            else
                std::cout << '.';
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << ' ';
    for (int i = 0; i <= _max_x + 1; ++i)
    {
        std::cout << ' ' << i;
    }
    std::cout << std::endl;
}

