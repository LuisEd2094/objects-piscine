#include <Rooms/ClassRoom.hpp>
#include <Person/Professor.hpp>
#include <Person/Student.hpp>

ClassRoom::~ClassRoom() {}
ClassRoom::ClassRoom(Course *p_course) : Room(std::type_index(typeid(Professor)),
                                              std::type_index(typeid(Student))),
                                         _currentCourse(p_course)
{
    addToList(this);
}
ClassRoom::ClassRoom() : Room(std::type_index(typeid(Professor)),
                              std::type_index(typeid(Student))),
                         _currentCourse(nullptr)
{
    addToList(this);
}

void ClassRoom::assignCourse(Course *p_course)
{
    _currentCourse = p_course;
};