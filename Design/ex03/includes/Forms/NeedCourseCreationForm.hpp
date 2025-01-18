#ifndef NEEDCOURSECREATIONFORM_HPP
#define NEEDCOURSECREATIONFORM_HPP

#include <Forms/Form.hpp>
#include <enums.hpp>

class NeedCourseCreationForm : public Form
{
private:
    CourseType _course_type;

public:
    NeedCourseCreationForm(CourseType course_type);
    void onExectute();
    ~NeedCourseCreationForm();
};

#endif
