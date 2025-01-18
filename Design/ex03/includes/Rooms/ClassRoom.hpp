#ifndef CLASSROOM_HPP
#define CLASSROOM_HPP

#include <Rooms/Room.hpp>

class Course;
class ClassRoom : public Room
{
private:
	Course *_currentCourse;

public:
	ClassRoom();
	ClassRoom(Course *p_course);
	~ClassRoom();
	void assignCourse(Course *p_course);
};

#endif
