#include <Bank.hpp>
#include <Account.hpp>

/**
 * @brief Construct a new Bank:: Bank object.
 * 
 * Initializes _accounts_pool to hold MAX_ACCOUNTS Account objects
 * _liquidity is set to INITIAL_BANK_LIQUIDITY
 * 
 */
Bank::Bank(): _liquidity(INITIAL_BANK_LIQUIDITY), _lent(0), _ids(0) 
{
    _accounts_pool.reserve(MAX_ACCOUNTS);
    for (std::size_t i = 0; i < MAX_ACCOUNTS; ++i)
        _accounts_pool.push_back(Account());
}

Bank::~Bank()
{
    
}

/**
 * @brief Adds amount * BANKS_CUT (5%) to banks liquidity
 * 
 * @param amount 
 */
void Bank::addToLiquidity(double amount)
{
    _liquidity += amount * BANKS_CUT;
}

/**
 * @brief Checks _accounts_pool for available object.
 * 
 * @param amount initial amount on the account, %5 is added to Bank liquidity
 * @return account_id of the newly used id or 
 * @return 0 if no object is available
 */
Account* Bank::createAccount(double amount)
{
    for (std::size_t i = 0; i < MAX_ACCOUNTS; ++i)
    {
        if (!_accounts_pool[i]._used)
        {
            _accounts_pool[i]._used = true;
            _accounts_pool[i]._id = ++_ids;
            _accounts_pool[i]._balance = amount - (amount * BANKS_CUT);
            addToLiquidity(amount);
            return (&_accounts_pool[i]);
        }
    }
    return (NULL);
}




double Bank::getLiquidity()
{
    return _liquidity;
}

/**
 * @brief Returns const address of account object from pool
 * 
 * @param id of the Account, given to you when the account is created
 * @return const Account* 
 */
Account* Bank::getAccount(std::size_t id)
{
    for (int i = 0; i < MAX_ACCOUNTS; ++i)
    {
        if (_accounts_pool[i]._id == id)
            return (&_accounts_pool[i]);
    }
    return (NULL);
}


/**
 * @brief calls reset function of the account.
 *          Account throws Account::AccountException (std::exception) if it has a pending loan
 * @param id 
 */
void Bank::deleteAccount(Account* acc)
{
    if (!acc)
        return;
    if (acc->_loan != 0)
        throw Exception("Account has outstanding amount");
    acc->_id = 0;
    acc->_balance = 0;
    acc->_used = false;
}

/**
 * @brief Checks if we have reached the 20% of our liquidity before giving out a loan
 * 
 * @param acc 
 * @param amount 
 */
void Bank::giveLoan(Account * acc, double amount)
{
    if (!acc)
        return;
    if (amount + _lent > _liquidity * MAX_BANK_DEBT)
        throw Exception("Bank can't give out a loan since it's reached its max debt!");
    
    acc->_loan += amount;
    acc->_balance += amount;
    _lent += amount;
}

/**
 * @brief if acc has any outstanding loan, it'd make amount payment to it.
 * 
 * @param acc 
 * @param amount 
 * @return Returns -1 if there is no loan, a positive number or 0 if amount >= loan or negative number if amount is greater than  
 */
void Bank::makePayment(Account * acc, double amount)
{
    if (!acc)
        return;
    if (acc->_loan > 0)
    {
        acc->_loan -= amount;
        if (acc->_loan < 0)
        {
            deposit(acc, acc->_loan * -1);
            acc->_loan = 0;
        }
    }
}
/**
 * @brief Acc->_balance is increased by amount - BANKS_CUT and bank._liquidity is increased by BANKS 
 * 
 * @param acc 
 * @param amount 
 */
void Bank::deposit(Account * acc, double amount)
{
    if (!acc)
        return;
    acc->_balance += amount - (amount * BANKS_CUT);
    addToLiquidity(amount);
}
