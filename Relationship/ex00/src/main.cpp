#include <Shovel.hpp>
#include <Worker.hpp>
#include <Hammer.hpp>

int main(void)
{
    Worker*  worker = new Worker();
    Worker*  worker2 = new Worker();
    Shovel* shovel = new Shovel();
    Hammer* hammer = new Hammer();



    worker->setTool(shovel);


    worker2->setTool(hammer);
    worker2->setTool(shovel);

    delete worker2;
    delete worker;

}