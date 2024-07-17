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

/**
 * @brief sets values to default
 * 
 */
void Account::reset()
{
    if (_loan != 0)
        throw Exception("Account has outstanding amount");
    _id = 0;
    _balance = 0;
    _used = false;
}


double Account::getLoan() const
{
    return (_loan);
}

/**
 * @brief Adds amount to the current _loan balance
 * 
 * @param amount 
 */
void Account::setLoan(double amount)
{
    /*Should the bank get a 5% cut from their own loan?*/
    _loan += amount;
    _balance += amount;
}

/**
 * @brief adds amount to balance according to amount - (amount * BANKS_CUT) formula
 * 
 * @param amount 
 */
void Account::addBalance(double amount)
{
    _balance += amount - (amount * BANKS_CUT);
}

std::ostream& operator << (std::ostream& os, const Account& obj)
{
    os << "Account id: " << obj._id << std::endl;
    os << "Account balance: " << obj._balance << std::endl;
    os << "Account loan: " << obj._loan  << std::endl;
    return (os);
}
