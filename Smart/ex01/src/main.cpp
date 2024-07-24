#include <command.hpp>
#include <packageReductionDiscount.hpp>
#include <thuesdayDiscount.hpp>

void seePrice(const command& command)
{
    std::cout << "Price for this command: " << command.get_total_price() << std::endl;
}

int main(void)
{
    std::list<article> arts;

    arts.push_back(article(10, 1, "Tomato"));    
    arts.push_back(article(20, 3, "Potato"));    
    arts.push_back(article(10, 1, "Banana"));
    arts.push_back(article(150, 1, "Bananas"));

    command command("Juan", arts);
    thuesdayDiscount thues("This is thuesday", arts);
    packageReductionDiscount pack("This is packet", arts);

    (void)command;    

    seePrice(command);
    seePrice(thues);
    seePrice(pack);
}