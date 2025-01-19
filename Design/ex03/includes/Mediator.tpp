#include <Mediator.hpp>

template <typename... Args, typename E>
void Mediatee::receive(E &event, Args &&...args)
{
    (void)event;
    (void)std::initializer_list<int>{(static_cast<void>(args), 0)...};
}

template <typename... Args, typename E>
void Mediatee::receive(E event, Args &&...args)
{
    (void)event;
    (void)std::initializer_list<int>{(static_cast<void>(args), 0)...};
}

template <typename... Args, typename M, typename E>
void Mediator::notify(M *mediated, E &event, Args &&...args)
{
    if (_mediated.empty() || !mediated)
        return;
    if (_mediated.contains(mediated))
        mediated->receive(event, std::forward<Args>(args)...);
}

template <typename... Args, typename M, typename E>
void Mediator::notify(M *mediated, E event, Args &&...args)
{
    if (_mediated.empty() || !mediated)
        return;
    if (_mediated.contains(mediated))
        mediated->receive(event, std::forward<Args>(args)...);
}

template <typename... Args, typename E>
void Mediator::receive(E event, Args &&...args)
{
    (void)event;
    (void)std::initializer_list<int>{(static_cast<void>(args), 0)...};
}
