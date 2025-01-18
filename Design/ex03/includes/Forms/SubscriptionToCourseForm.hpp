#ifndef SUBSCRIPTIONTOCOURSEFORM_HPP
#define SUBSCRIPTIONTOCOURSEFORM_HPP

#include <Forms/Form.hpp>
class Course;
class Student;
class SubscriptionToCourseForm : public Form
{
private:
    Course *_course;
    Student *_student;
public:
    SubscriptionToCourseForm(Course * p_course, Student * p_student);
    void onExectute();
    ~SubscriptionToCourseForm();
};

#endif