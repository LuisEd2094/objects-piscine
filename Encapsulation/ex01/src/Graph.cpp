#include <Graph.hpp>

Graph::Graph():
        _size(Vector2(0,0)),
        _max_x(0),
        _max_y(0)
{

}

Graph::Graph(const std::string &file):
        _size(Vector2(0,0)),
        _max_x(0),
        _max_y(0)
{
    std::ifstream ifs(file.c_str());
    if (!ifs.is_open())
        throw std::runtime_error("Couldn't open file");
    std::string line;
    while (std::getline(ifs, line))
    {
        std::vector<std::string> result = split(line, ',');
        if (result.size() != 2 || !is_only_digits(result[0]) || !is_only_digits(result[1]))
            throw std::runtime_error("Invalid file format");
        addVector(std::atoi(result[0].c_str()), std::atoi(result[1].c_str()));
    }
    ifs.close();
}
Graph::~Graph(){}

bool compareVectors(Vector2 a, Vector2 b)
{
    if (a.points[0] == b.points[0])
        return a.points[1] < b.points[1];
    return a.points[0] > b.points[0];
}

/**
 * @brief Adds new vector to the graph
 * Updates the size of the graph
 */
void Graph::addVector(float y, float x)
{
    _vectors.push_back(Vector2(y,x));
    _max_x = std::max(_max_x, (int)x);
    _max_y = std::max(_max_y, (int)y);
    _size =  Vector2(_max_y + 1, _max_x + 1);
}
 
/**
 * @brief Adds a line to the graph using the Bresenham's line algorithm
 * Updates the size of the graph
 */

void Graph::addLine(const Vector2 &a, const Vector2 &b)
{
    int dx = b.points[1] - a.points[1];
    int dy = b.points[0] - a.points[0];

    // Handle infinite slope
    if (dx == 0) {
        for (int y = std::min(a.points[0], b.points[0]); y <= std::max(a.points[0], b.points[0]); ++y)
        {
            addVector(a.points[1], y);
        }
        return;
    }

    float m = static_cast<float>(dy) / static_cast<float>(dx);
    float c = a.points[0] - m * a.points[1];

    for (int x = std::min(a.points[1], b.points[1]); x <= std::max(a.points[1], b.points[1]); ++x)
    {
        int y = static_cast<int>(round(m * x + c));
        addVector(x, y);
    }
}

Vector2 Graph::getSize() const
{
    return _size;
}

/**
 * @brief Prints the graph to the console
 */
void Graph::printGraph()
{
    if (_vectors.empty())
        throw std::runtime_error("No vectors to print");
    std::list<Vector2> sorted = _vectors;
    sorted.sort(compareVectors);
    std::list<Vector2>::const_iterator it = sorted.begin();
    std::list<Vector2>::const_iterator it2 = sorted.end();
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

