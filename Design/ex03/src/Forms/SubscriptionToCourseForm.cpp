#include <Forms/SubscriptionToCourseForm.hpp>
#include <Course.hpp>
#include <Person/Student.hpp>
SubscriptionToCourseForm::SubscriptionToCourseForm(Course *p_course, Student *p_student) : Form(FormType::SubscriptionToCourse),
                                                                                           _course(p_course),
                                                                                           _student(p_student) {};
void SubscriptionToCourseForm::onExectute()
{
    _course->subscribe(_student);
    std::cout << "Subscription form executed" << std::endl;
};
SubscriptionToCourseForm::~SubscriptionToCourseForm() {};