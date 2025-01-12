#ifndef NEEDCOURSECREATIONFORM_HPP
#define NEEDCOURSECREATIONFORM_HPP

#include <Forms/Form.hpp>

class NeedCourseCreationForm : public Form
{
private:
public:
    NeedCourseCreationForm() : Form(FormType::NeedCourseCreation) {};
    void onExectute()
    {
        std::cout << "NeedCourseCreation form executed" << std::endl;
    };
    ~NeedCourseCreationForm(){};
};

#endif
