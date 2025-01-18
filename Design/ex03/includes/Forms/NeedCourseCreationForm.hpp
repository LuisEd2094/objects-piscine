#ifndef NEEDCOURSECREATIONFORM_HPP
#define NEEDCOURSECREATIONFORM_HPP

#include <Forms/Form.hpp>
#include <Lists/CourseList.hpp>

class NeedCourseCreationForm : public Form
{
private:
    CourseType _course_type;
public:
    NeedCourseCreationForm(CourseType course_type) : Form(FormType::NeedCourseCreation), _course_type(course_type){

        _course_type = course_type;
    };
    void onExectute()
    {
        Singleton<CourseList>::getInstance().push_back(Course(_course_type));
        std::cout << "NeedCourseCreation form executed" << std::endl;
    };
    ~NeedCourseCreationForm(){};
};

#endif
