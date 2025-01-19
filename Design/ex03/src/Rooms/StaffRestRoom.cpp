#include <StaffRestRoom.hpp>
#include <Person/Staff.hpp>
StaffRestRoom::StaffRestRoom() : Room(std::type_index(typeid(Staff)))
{
    addToList(this);
};
StaffRestRoom::~StaffRestRoom() 
{

};