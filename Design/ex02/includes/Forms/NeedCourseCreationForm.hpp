#ifndef NEEDCOURSECREATIONFORM_HPP
#define NEEDCOURSECREATIONFORM_HPP

#include <Forms/Form.hpp>
#include <Lists/CourseList.hpp>

class NeedCourseCreationForm : public Form
{
private:
    std::string _course_name;
public:
    NeedCourseCreationForm(const std::string& course_name) : Form(FormType::NeedCourseCreation), _course_name(course_name){

        _course_name = course_name;
    };
    void onExectute()
    {
        Singleton<CourseList>::getInstance().push_back(Course(_course_name));
        std::cout << "NeedCourseCreation form executed" << std::endl;
    };
    ~NeedCourseCreationForm(){};
};

#endif
