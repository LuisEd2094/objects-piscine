#ifndef SECRETARY_HPP
#define SECRETARY_HPP

#include <Person/Staff.hpp>
#include <Mediator.hpp>
#include <enums.hpp>

class Secretary : public Staff, public Mediatee
{
private:
    Secretary();
    void receive(const std::string& event);

public:
    template <typename... Args>
    Form *createForm(FormType p_formType, Args &&...args);
    void archiveForm();
    Secretary(std::string p_name);
    ~Secretary();
};

#include <Person/Secretary.tpp>

#endif