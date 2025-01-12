#include <Person/Secretary.hpp>

Form *Secretary::createForm(FormType p_formType)
{
    return FormFactory::createForm(p_formType);
}