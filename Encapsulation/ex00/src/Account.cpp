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

/**
 * @brief gets account id
 * 
 * @return std::size_t 
 */
std::size_t Account::getId() const
{
    return _id;
}

/**
 * @brief gets account balance
 * 
 * @return double 
 */

double Account::getBalance() const
{
    return _balance;
}



std::ostream& operator << (std::ostream& os, const Account& obj)
{
    os << "Account id: " << obj._id;

    return (os);
}
