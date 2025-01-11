#ifndef HEADMASTER_HPP
#define HEADMASTER_HPP

#include <Person/Staff.hpp>
#include <List.hpp>
class Headmaster : public Staff
{
private:
    List<Form *> _formToValidate;
    Headmaster() : Staff("Headmaster") {}

public:
    void receiveForm(Form *p_form);
    Headmaster(std::string p_name) : Staff(p_name) {}
    void signForm(Form *p_form);
    void signForm();
    void executeForm(Form *p_form);
    void executeForm();

};

#endif