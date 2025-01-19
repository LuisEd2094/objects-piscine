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
    Mediatee(Mediator *);

public:
    template <typename... Args, typename E>
    void receive(E &, Args &&...);

    template <typename... Args, typename E>
    void receive(E, Args &&...);
    virtual ~Mediatee() = 0;
};

class Mediator
{
protected:
    List<Mediatee *> _mediated;

public:
    template <typename... Args, typename M, typename E>
    void notify(M *, E&, Args &&...);

    template <typename... Args, typename M, typename E>
    void notify(M *, E, Args &&...);
    
    template <typename... Args, typename E>
    void receive(E, Args &&...);

    void registerMediatee(Mediatee *);
    virtual ~Mediator() = 0;
};

#include <Mediator.tpp>

#endif