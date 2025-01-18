#ifndef SECRETARY_TPP
#define SECRETARY_TPP
#include <Person/Secretary.hpp> 
#include <Forms/FormFactory.hpp>

template <typename... Args>
Form *Secretary::createForm(FormType p_formType, Args &&...args)
{
    return FormFactory::createForm(p_formType, std::forward<Args>(args)...);
}
#endif
