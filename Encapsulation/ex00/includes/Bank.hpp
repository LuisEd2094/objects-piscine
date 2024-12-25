#ifndef BANK_HPP
# define BANK_HPP
# ifndef MAX_ACCOUNTS
#   define MAX_ACCOUNTS 5000
# endif
# ifndef INITIAL_BANK_LIQUIDITY
#  define INITIAL_BANK_LIQUIDITY 10000.00
# endif
# ifndef MAX_BANK_DEBT
#   define MAX_BANK_DEBT 0.2 /*Arbitrary % */
# endif
# ifndef BANKS_CUT
#  define BANKS_CUT 0.05
# endif

# include <vector>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <sstream>
# include <Exception.hpp>

class Account;

class Bank
{
    public:
        Bank();
        ~Bank();

        Account*    createAccount(double);

        Account*    getAccount(std::size_t);

        void        deleteAccount(Account*);
        void        giveLoan(Account *, double);
        void        makePayment(Account *, double);
        void        deposit(Account *, double);
        void        withdraw(Account *, double);

        double      getLiquidity();



    private:
        std::vector<Account>    _accounts_pool;
        double                  _liquidity;
        double                  _lent;
        std::size_t             _ids;
        void                    addToLiquidity(double);
};





#endif