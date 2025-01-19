#ifndef HEADMASTER_HPP
#define HEADMASTER_HPP

#include <Person/Staff.hpp>
#include <Mediator.hpp>
#include <enums.hpp>

template <typename T>
class Singleton;
class From;
class Headmaster : public Staff, public Mediator
{
private:
    List<Form *> _formToValidate;
    friend class Singleton<Headmaster>;
    Headmaster();

public:
    void receiveForm(Form *p_form);
    void signForm(Form *p_form);
    void signForm();
    void executeForm(Form *p_form);
    void executeForm();
    
    template <typename... Args, typename E>
    void receive(E, Args &&...);
    ~Headmaster();
};

#include <Person/Headmaster.tpp>

#endif