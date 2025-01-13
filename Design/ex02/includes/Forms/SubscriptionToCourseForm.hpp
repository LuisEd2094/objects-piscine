#ifndef SUBSCRIPTIONTOCOURSEFORM_HPP
#define SUBSCRIPTIONTOCOURSEFORM_HPP

#include <Forms/Form.hpp>
class SubscriptionToCourseForm : public Form
{
private:
    Course *_course;
    Student *_student;
public:
    SubscriptionToCourseForm(Course * p_course, Student * p_student) : Form(FormType::SubscriptionToCourse), _course(p_course), _student(p_student) {};
    void onExectute()
    {
        _course->subscribe(_student);
        std::cout << "Subscription form executed" << std::endl;
    };
    ~SubscriptionToCourseForm(){};
};

#endif