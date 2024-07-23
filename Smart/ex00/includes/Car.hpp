#ifndef CAR_HPP
# define CAR_HPP

# include <iostream>

class Car
{
    public:
        Car(): _on(false), _speed(0), _gears(1), _reverse(false), _angle(90)  {};
        ~Car() {};
        bool checkIfOn() {if (!_on) {std::cout << "Car is off! Can't do anything!" << std::endl; return false;} return true;};
        void start() {if (!_on) {std::cout << "Car started, brr brr" << std::endl; _on = true;}}; 
        void stop() {if (_on) {std::cout << "Car stoped, no brr" << std::endl; _on = false;}};
        void accelerate(std::size_t speed) {if (!checkIfOn())return;  _speed += speed; std::cout << "Car is now going at " << _speed << std::endl; };
        void shift_gears_up() {if (!checkIfOn()) {return;} std::cout << "Car is on gear " << ++_gears << std::endl;};
        void shift_gears_down(){if (!checkIfOn()) {return;} if (_gears > 1) {std::cout << "Car is on gear " << --_gears << std::endl;} else {std::cout << "Car can't go any lower gear!" << std::endl;} };
        void reverse() {if (!checkIfOn()) {return;} _reverse = !_reverse; if (_reverse) {std::cout << "Car is now on reverse" << std::endl;} else {std::cout << "Car is now going forward" << std::endl;} };
        void turn_wheel(std::size_t angle){_angle += angle; std::cout << "Car is now at a " << _angle << " angle" << std::endl;};
        void straighten_wheels() {_angle = 90; std::cout << "Car is once again looking straight ahead!" << std::endl;};
        void apply_force_on_brakes(std::size_t force) {if (force > _speed){_speed = 0;}else{_speed -= force;} std::cout << "Car applied brakes, current speed: " << _speed << std::endl;};
        void apply_emergency_brakes(){_speed = 0; std::cout << "Emergency breaks, Car is now stoped" << std::endl;};
    private:
        bool            _on;
        std::size_t     _speed;
        std::size_t     _gears;
        bool            _reverse;
        std::size_t     _angle; 
};

#endif