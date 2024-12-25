#include <Bank.hpp>
#include <Account.hpp>

/**
 * @brief Construct a new Bank:: Bank object.
 *
 * Initializes _accounts_pool to hold MAX_ACCOUNTS Account objects
 * _liquidity is set to INITIAL_BANK_LIQUIDITY
 *
 */
Bank::Bank() : _liquidity(INITIAL_BANK_LIQUIDITY), _lent(0), _ids(0)
{
}

Bank::~Bank()
{
    for (std::map<std::size_t, Account *>::iterator it = _accounts_pool.begin(); it != _accounts_pool.end(); ++it)
    {
        delete it->second;
    }
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
Account *Bank::createAccount(double amount)
{
    if (_ids >= MAX_ACCOUNTS)
        throw Exception("Bank has reached its maximum account limit");
    Account *acc = new Account();
    _accounts_pool[_ids] = acc;
    acc->_id = _ids;
    acc->_balance = amount - (amount * BANKS_CUT);
    addToLiquidity(amount);
    ++_ids;
    return (acc);
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
Account *Bank::getAccount(std::size_t id)
{
    return (_accounts_pool[id]);
}

/**
 * @brief Returns address of account object from pool
 */

Account *Bank::operator[](std::size_t id)
{
    return getAccount(id);
}

/**
 * @brief calls reset function of the account.
 *          Account throws Account::AccountException (std::exception) if it has a pending loan
 * @param id
 */
void Bank::deleteAccount(Account *acc)
{
    if (!acc)
        return;
    if (acc->_loan != 0)
        throw Exception("Account has outstanding amount");
    _accounts_pool.erase(acc->_id);
    delete acc;
}

/**
 * @brief Checks if we have reached the 20% of our liquidity before giving out a loan
 *
 * @param acc
 * @param amount
 */
void Bank::giveLoan(Account *acc, double amount)
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
void Bank::makePayment(Account *acc, double amount)
{
    if (!acc)
        return;
    if (acc->_loan > 0)
    {
        if (amount > acc->_loan)
        {
            throw Exception("Amount is greater than loan");
        }
        acc->_loan -= amount;
    }
}
/**
 * @brief Acc->_balance is increased by amount - BANKS_CUT and bank._liquidity is increased by BANKS
 *
 * @param acc
 * @param amount
 */
void Bank::deposit(Account *acc, double amount)
{
    if (!acc)
        return;
    acc->_balance += amount - (amount * BANKS_CUT);
    addToLiquidity(amount);
}
