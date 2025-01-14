#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include <Rooms/Room.hpp>
#include <Person/Professor.hpp>
#include <Person/Student.hpp>

class Classroom : public Room
{
private:
	Course *_currentCourse;

public:
	Classroom(Course *p_course) : Room(std::type_index(typeid(Professor)), std::type_index(typeid(Student))), _currentCourse(p_course) {}
	Classroom() : Room(std::type_index(typeid(Professor)), std::type_index(typeid(Student))), _currentCourse(nullptr) {}

	void assignCourse(Course *p_course) { _currentCourse = p_course; };
};

#endif
