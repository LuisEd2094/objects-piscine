#ifndef ENUMS_HPP
# define ENUMS_HPP


enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
    SubscriptionToCourse,
	AssignProffesorToCourse,
	COUNT,
};

enum class CourseType
{
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
	CreateCourse,
	COUNT,
};


#endif  