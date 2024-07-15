#include <Account.hpp>
#include <Bank.hpp>


Account::Account(): _id(0), _balance(0), _used(false)
{

}

Account::~Account()
{

}


std::size_t Account::getId() const
{
    return _id;
}