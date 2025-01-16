#ifndef MEDIATOR_HPP
# define MEDIATOR_HPP

#include <string>
#include <Lists/List.hpp>
class Mediator;
class Mediatee
{
protected:
    Mediator* _mediator;
    Mediatee(Mediator* mediator) : _mediator(mediator) {};
public:
    virtual void receive(const std::string& event) = 0;
    virtual ~Mediatee() = 0;
};

class Mediator
{
    private:
    List<Mediatee*> _mediated;
public:
    void notify(Mediatee* sender, const std::string& event)
    {
        if (_mediated.empty() || !sender)
            return;
        if (_mediated.contains(sender))
            sender->receive(event);
    }
    void registerMediatee(Mediatee* mediatee)
    {
        _mediated.push_back(mediatee);
    }
    virtual ~Mediator() = default;


};


#endif