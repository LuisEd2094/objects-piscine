#include <Bank.hpp>
#include <Account.hpp>

/**
 * @brief Construct a new Bank:: Bank object.
 * 
 * Initializes _accounts_pool to hold MAX_ACCOUNTS Account objects
 * _liquidity is set to INITIAL_BANK_LIQUIDITY
 * 
 */
Bank::Bank(): _liquidity(INITIAL_BANK_LIQUIDITY), _ids(0) 
{
    _accounts_pool.reserve(MAX_ACCOUNTS);
    for (std::size_t i = 0; i < MAX_ACCOUNTS; ++i)
        _accounts_pool.push_back(Account());
}

Bank::~Bank()
{
    
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
            _accounts_pool[i]._balance = amount * 0.95;
            _liquidity += amount * 0.05;
            return (&_accounts_pool[i]);
        }
    }
    return (NULL);
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
 * @brief calls reset function of the account
 * 
 * @param id 
 */
void Bank::deleteAccount(Account* acc)
{
    if (!acc)
        return;
    acc->reset();
}

/**
 * @brief searches for account with account id and resets it
 * 
 * @param id 
 */
void Bank::deleteAccount(std::size_t id)
{
    for (int i = 0; i < MAX_ACCOUNTS; ++i)
    {
        if (_accounts_pool[i]._id == id)
        {
            _accounts_pool[i].reset();
        }
    }
}