#include <Secretary.hpp>
#include <Singleton.hpp>
#include <Headmaster.hpp>

Secretary::Secretary() : Staff("Secretary"), 
Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {}
Secretary::Secretary(std::string p_name) : Staff(p_name), 
Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {}
Secretary::~Secretary() {};

void Secretary::receive(const std::string &event)
{
    static_cast<void>(event);
};
void Secretary::archiveForm() {};