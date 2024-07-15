#ifndef BANK_HPP
# define BANK_HPP
# define MAX_ACCOUNTS 5000
# define INITIAL_BANK_LIQUIDITY 10000.00

# include <vector>
# include <cstddef>
# include <cstring>
# include <iostream>


class Account;

class Bank
{
    public:
        Bank();
        ~Bank();

        bool CreateAccount(double);

    private:
        std::vector<Account>    _accounts_pool;
        double                  _liquidity;
        std::size_t             _ids;
};





#endif