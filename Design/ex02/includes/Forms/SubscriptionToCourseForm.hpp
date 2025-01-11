#ifndef SUBSCRIPTIONTOCOURSEFORM_HPP
#define SUBSCRIPTIONTOCOURSEFORM_HPP

#include <Forms/Form.hpp>
class SubscriptionToCourseForm : public Form
{
private:
public:
    SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse) {};
    void onExectute()
    {
        std::cout << "Subscription form executed" << std::endl;
    };
};

#endif