#ifndef ENUMS_HPP
# define ENUMS_HPP


enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
    SubscriptionToCourse,
	AssignProfessorToCourse,
	COUNT,
};

enum class CourseType
{
	NONE,
	Math,
	Physics,
	Chemistry,
	ComputerScience,
	English,
	History,
	Geography,
	French,
	COUNT,
};

enum class Event
{
	RingBell,
	AssignProfessorToCourse,
	COUNT,
};


#endif  