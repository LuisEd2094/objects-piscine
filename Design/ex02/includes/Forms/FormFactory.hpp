#ifndef FORMFACTORY_HPP
#define FORMFACTORY_HPP

#include <Forms/Form.hpp>
#include <Person/Secretary.hpp>
#include <Person/Headmaster.hpp>

class FormFactory
{
private:
    FormFactory() = delete;
    static Form *createForm(FormType p_formType);
    friend class Secretary;
};

#endif
