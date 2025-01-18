#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include <string>
#include <Lists/List.hpp>
#include <iostream>

class Mediator;
class Mediatee
{
protected:
    Mediator *_mediator;
    Mediatee(Mediator *mediator) : _mediator(mediator) {};

public:
    template <typename... Args>
    void receive(const std::string &event, Args &&...args)
    {
        std::cout << "Mediatee received event: " << event << std::endl;
    }
    virtual ~Mediatee() = 0;
};

class Mediator
{
private:
    List<Mediatee *> _mediated;

public:
    template <typename... Args, typename M>
    void notify(M *sender, const std::string &event, Args &&...args)
    {
        if (_mediated.empty() || !sender)
            return;
        if (_mediated.contains(sender))
            sender->receive(event, std::forward<Args>(args)...);
    }
    void registerMediatee(Mediatee *mediatee)
    {
        _mediated.push_back(mediatee);
    }
    virtual ~Mediator() = default;
};

#endif