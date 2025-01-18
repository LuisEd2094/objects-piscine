#ifndef ASSIGNPROFESSORTOCOURSE_HPP
#define ASSIGNPROFESSORTOCOURSE_HPP

#include <Forms/Form.hpp>
#include <Course.hpp>
#include <Person/Professor.hpp>
class AssignProfessorToCourse : public Form
{
private:
    Course *_course;
    Professor *_professor;

public:
    SubscriptionToCourseForm(Course *p_course, Professor *p_professor) : Form(FormType::AssignProffesorToCourse),
                                                                         _course(p_course),
                                                                         _professor(p_professor) {};
    void onExectute()
    {
        _course->assign(_professor);
        std::cout << "Assign form executed" << std::endl;
    };
    ~SubscriptionToCourseForm() {};
};

#endif
