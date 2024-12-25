#include <Account.hpp>
#include <Bank.hpp>

/**
 * @brief Construct a new Account::Account object
 * 
 */
Account::Account(): _id(0), _balance(0), _loan(0), _used(false)
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


double Account::getLoan() const
{
    return (_loan);
}

std::ostream& operator << (std::ostream& os, const Account& obj)
{
    os << "Account id: " << obj._id << std::endl;
    os << "Account balance: " << obj._balance << std::endl;
    os << "Account loan: " << obj._loan  << std::endl;
    return (os);
}
