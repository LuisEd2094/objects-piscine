#include <Account.hpp>
#include <Bank.hpp>

/**
 * @brief Construct a new Account:: Account object
 * 
 */
Account::Account(): _id(0), _balance(0), _used(false)
{

}

/**
 * @brief Destroy the Account:: Account object
 * 
 */
Account::~Account()
{

}

bool Account::getUsed() const
{
    return _used;
}


std::size_t Account::getId() const
{
    return _id;
}

double Account::getBalance() const
{
    return _balance;
}

/**
 * @brief sets values to default
 * 
 */
void Account::reset()
{
    _id = 0;
    _balance = 0;
    _used = false;
}

std::ostream& operator << (std::ostream& os, const Account& obj)
{
    os << "Account id: " << obj._id;
    return (os);
}
