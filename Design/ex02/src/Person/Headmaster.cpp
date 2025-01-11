#include <Person/Headmaster.hpp>
#include <Forms/Form.hpp>

void Headmaster::receiveForm(Form *p_form)
{
    _formToValidate.push_back(p_form);
}

void Headmaster::signForm()
{
    for (auto form : _formToValidate)
    {
        form->sign();
    }
}

void Headmaster::executeForm()
{
    for (auto form : _formToValidate)
    {
        form->execute();
    }
}

void Headmaster::signForm(Form *p_form)
{
    p_form->sign();
}

void Headmaster::executeForm(Form *p_form)
{
    p_form->execute();
}

