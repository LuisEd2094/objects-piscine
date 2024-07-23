#include <command.hpp>
int main(void)
{
    std::list<article> arts;

    arts.push_back(article(10, 1, "Tomato"));    
    arts.push_back(article(20, 3, "Potato"));    
    arts.push_back(article(10, 1, "Banana"));

    command command("Juan", arts);

    (void)command;    

}