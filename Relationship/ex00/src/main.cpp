#include <Shovel.hpp>
#include <Worker.hpp>
#include <Hammer.hpp>
#include <Workshop.hpp>

int main(void)
{
    Worker*  worker = new Worker();
    Worker*  worker2 = new Worker();
    Shovel* shovel = new Shovel();
    Shovel* shovel2 = new Shovel();
    Hammer* hammer = new Hammer();

    Workshop workshopShovel(shovel);
    Workshop workshopHammer(hammer);

    worker->setTool(shovel);
    worker2->setTool(hammer);
    worker2->setTool(shovel2);


    worker->addWorkshop(&workshopShovel);
    workshopShovel.signUp(worker);
    workshopShovel.signUp(worker2);


    worker2->work();
    workshopShovel.executeWorkDay();
    delete worker2;
    delete worker;
    delete shovel;
    delete shovel2;
    delete hammer;
}