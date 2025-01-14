#ifndef SECRETARY_HPP
#define SECRETARY_HPP

#include <Person/Staff.hpp>
#include <Forms/FormFactory.hpp>

class Secretary : public Staff
{
private:
    Secretary() : Staff("Secretary") {}

public:
    template <typename... Args>
    Form *createForm(FormType p_formType, Args &&...args)
    {
        return FormFactory::createForm(p_formType, std::forward<Args>(args)...);
    }
    void archiveForm();
    Secretary(std::string p_name) : Staff(p_name) {}
};

#endif