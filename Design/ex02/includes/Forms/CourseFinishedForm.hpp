#ifndef COURSEFINISHEDFORM_HPP
#define COURSEFINISHEDFORM_HPP

#include <Forms/Form.hpp>
class CourseFinishedForm : public Form
{
private:
	Course *_course;

public:
	CourseFinishedForm(Course *p_course) : Form(FormType::CourseFinished), _course(p_course) {};
	void onExectute()
	{
		std::cout << "Course finished form executed" << std::endl;
	};
};

#endif