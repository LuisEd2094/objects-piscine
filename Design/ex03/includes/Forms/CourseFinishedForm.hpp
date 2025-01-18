#ifndef COURSEFINISHEDFORM_HPP
#define COURSEFINISHEDFORM_HPP

#include <Forms/Form.hpp>

class Course;
class CourseFinishedForm : public Form
{
private:
	Course *_course;

public:
	CourseFinishedForm(Course* course);
	void onExectute();
    ~CourseFinishedForm();
};
	

#endif