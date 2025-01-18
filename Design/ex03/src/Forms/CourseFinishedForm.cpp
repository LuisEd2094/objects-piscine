#include <CourseFinishedForm.hpp>
#include <Course.hpp>

CourseFinishedForm::CourseFinishedForm(Course *course) : Form(FormType::CourseFinished),
                                                         _course(course) {};
void CourseFinishedForm::onExectute()
{
    _course->setFinished(true);
};
CourseFinishedForm::~CourseFinishedForm() {};