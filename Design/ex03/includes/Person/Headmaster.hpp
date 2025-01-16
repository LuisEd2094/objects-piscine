#ifndef HEADMASTER_HPP
#define HEADMASTER_HPP

#include <Person/Staff.hpp>
#include <Forms/FormCommander.hpp>
#include <Forms/Form.hpp>
#include <List.hpp>

class Headmaster : public Staff, public Mediator
{
private:
    List<Form *> _formToValidate;
    friend class Singleton<Headmaster>;
    Headmaster() : Staff("Headmaster") {}

public:
    void receiveForm(Form *p_form);
    void signForm(Form *p_form);
    void signForm();
    void executeForm(Form *p_form);
    void executeForm();
    ~Headmaster() {};
};

#endif