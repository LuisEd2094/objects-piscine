#include <Mediator.hpp>


template <typename... Args>
void Mediatee::receive(const std::string &event, Args &&...args)
{
    std::cout << "Mediatee received event: " << event << std::endl;
}

template <typename... Args, typename M>
void Mediator::notify(M *sender, const std::string &event, Args &&...args)
{
    if (_mediated.empty() || !sender)
        return;
    if (_mediated.contains(sender))
        sender->receive(event, std::forward<Args>(args)...);
}
