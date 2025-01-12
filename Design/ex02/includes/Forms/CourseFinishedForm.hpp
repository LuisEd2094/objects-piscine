#ifndef COURSEFINISHEDFORM_HPP
#define COURSEFINISHEDFORM_HPP

#include <Forms/Form.hpp>
class CourseFinishedForm : public Form
{
private:
	Course *_course;

public:
	CourseFinishedForm() : Form(FormType::CourseFinished) {};
	void onExectute()
	{
		std::cout << "Course finished form executed" << std::endl;
	};
    ~CourseFinishedForm(){};
};
	

#endif