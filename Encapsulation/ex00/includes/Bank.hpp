#ifndef BANK_HPP
# define BANK_HPP
# ifndef MAX_ACCOUNTS
#   define MAX_ACCOUNTS 5000
# endif
# ifndef INITIAL_BANK_LIQUIDITY
#  define INITIAL_BANK_LIQUIDITY 10000.00
# endif

# include <vector>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <sstream>


class Account;

class Bank
{
    public:
        Bank();
        ~Bank();

        Account*    createAccount(double);

        Account*  getAccount(std::size_t);

        void deleteAccount(std::size_t);
        void deleteAccount(Account*);



    private:
        std::vector<Account>    _accounts_pool;
        double                  _liquidity;
        std::size_t             _ids;
};





#endif