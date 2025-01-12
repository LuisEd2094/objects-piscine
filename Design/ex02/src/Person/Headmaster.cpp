#include <Person/Headmaster.hpp>

void Headmaster::receiveForm(Form *p_form)
{
    _formToValidate.push_back(p_form);
}

void Headmaster::signForm()
{
    for (auto form : _formToValidate)
    {
        FormCommander::sign(*form);
    }
}

void Headmaster::executeForm()
{
    for (auto form : _formToValidate)
    {
        FormCommander::execute(*form);
    }
}

void Headmaster::signForm(Form *p_form)
{
    FormCommander::sign(*p_form);
}

void Headmaster::executeForm(Form *p_form)
{
    FormCommander::execute(*p_form);
}

