#include <Forms/NeedCourseCreationForm.hpp>
#include <Singleton.hpp>
#include <Lists/CourseList.hpp>
#include <Course.hpp>

NeedCourseCreationForm::NeedCourseCreationForm(CourseType course_type) : Form(FormType::NeedCourseCreation),
                                                                         _course_type(course_type)
{

    _course_type = course_type;
};
void NeedCourseCreationForm::onExectute()
{
    Singleton<CourseList>::getInstance().push_back(Course(_course_type));
    std::cout << "NeedCourseCreation form executed" << std::endl;
};
NeedCourseCreationForm::~NeedCourseCreationForm() {};