#ifndef SECRETARY_HPP
#define SECRETARY_HPP

#include <Person/Staff.hpp>
#include <Forms/FormFactory.hpp>

class Headmaster;
class Secretary : public Staff, public Mediatee
{
private:
    Secretary() : Staff("Secretary"), Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {}
    void receive(const std::string& event) {static_cast<void>(event);};

public:
    template <typename... Args>
    Form *createForm(FormType p_formType, Args &&...args)
    {
        return FormFactory::createForm(p_formType, std::forward<Args>(args)...);
    }
    void archiveForm();
    Secretary(std::string p_name) : Staff(p_name),Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())){}
    ~Secretary() {};
};

#endif