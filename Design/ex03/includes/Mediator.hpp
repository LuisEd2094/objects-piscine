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
    Mediatee(Mediator *mediator);

public:
    template <typename... Args>
    void receive(const std::string &event, Args &&...args);
    virtual ~Mediatee() = 0;
};

class Mediator
{
protected:
    List<Mediatee *> _mediated;

public:
    template <typename... Args, typename M>
    void notify(M *sender, const std::string &event, Args &&...args);
    void registerMediatee(Mediatee *mediatee);
    virtual ~Mediator() = 0;
};

#include <Mediator.tpp>

#endif