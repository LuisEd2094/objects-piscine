#include <Car.hpp>
int main(void)
{
    Car car;

    car.start();
    car.stop();
    car.accelerate(50);
    car.shift_gears_down();
    car.shift_gears_up();
    car.reverse();
    car.reverse();
    car.turn_wheel(15);
    car.straighten_wheels();
    car.apply_force_on_brakes(25);
    car.apply_emergency_brakes();
   
}