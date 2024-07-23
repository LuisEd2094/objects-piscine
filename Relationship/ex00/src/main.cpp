#include <Shovel.hpp>
#include <Worker.hpp>
#include <Hammer.hpp>
#include <Workshop.hpp>

int main(void)
{
    Worker*  worker = new Worker();
    Worker*  worker2 = new Worker();
    Shovel* shovel = new Shovel();
    Hammer* hammer = new Hammer();

    Workshop workshopShovel(shovel);
    Workshop workshopHammer(hammer);

    worker->setTool(shovel);


    worker->addWorkshop(&workshopShovel);
    workshopHammer.signUp(worker);

    worker2->setTool(hammer);
    worker2->setTool(shovel);

    delete worker2;
    delete worker;

}