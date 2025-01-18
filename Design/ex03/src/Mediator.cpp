#include <Mediator.hpp>

Mediatee::Mediatee(Mediator *mediator) : _mediator(mediator) {};

Mediatee::~Mediatee() {}

void Mediator::registerMediatee(Mediatee *mediatee)
{
    _mediated.push_back(mediatee);
}

Mediator::~Mediator() {};