#include <Person/Staff.hpp>

Staff::Staff() : Person("Staff") {}
Staff::~Staff() {};
Staff::Staff(std::string p_name) : Person(p_name) {}
Staff::Staff(std::string p_name, Room *p_room) : Person(p_name, p_room) {}
