#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include <Rooms/Room.hpp>

class Classroom : public Room
{
private:
	Course *_currentRoom;

public:
	Classroom() : Room(), _currentRoom(nullptr) {}
	void assignCourse(Course *p_course);
};


#endif
