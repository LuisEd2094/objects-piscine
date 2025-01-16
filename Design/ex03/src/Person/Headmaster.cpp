#include <Person/Headmaster.hpp>


void Headmaster::receiveForm(Form *p_form)
{
    _formToValidate.push_back(p_form);
}

void Headmaster::signForm()
{
    for (auto form : _formToValidate)
    {
        FormCommander::FormSigner::sign(*form);
    }
}

void Headmaster::executeForm()
{
    for (auto form : _formToValidate)
    {
        FormCommander::FormExecutor::execute(*form);
    }
}

void Headmaster::signForm(Form *p_form)
{
    FormCommander::FormSigner::sign(*p_form);
}

void Headmaster::executeForm(Form *p_form)
{
    FormCommander::FormExecutor::execute(*p_form);
}

