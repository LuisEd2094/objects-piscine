#include <Person/Staff.hpp>
#include <Lists/StaffList.hpp>

#include <Person/Secretary.hpp>
#include <Person/Professor.hpp>
#include <Person/Headmaster.hpp>

void Staff::addToList(Staff *staff)
{
    StaffList staffList;
    staffList.push_back(staff);
}
Staff::Staff() : Person("Staff")
{
}
Staff::~Staff() {};
Staff::Staff(std::string p_name) : Person(p_name)
{
}
Staff::Staff(std::string p_name, Room *p_room) : Person(p_name, p_room)
{
}
