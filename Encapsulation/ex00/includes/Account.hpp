#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <cstdio>
#include <iostream>
#include <sstream>
#include <Exception.hpp>

class Bank;
class Account
{
    friend class Bank;

public:
    /*Account will only be usable through class Bank*/
    ~Account();
    std::size_t getId() const;
    double getBalance() const;
    double getLoan() const;
    class AccountException;

private:
    /*Only bank is able to create Account Objects*/

    std::size_t _id;
    double _balance;
    double _loan;

    Account();
    friend std::ostream &operator<<(std::ostream &, const Account &);
};

class Account::AccountException : public std::exception
{
private:
    std::string _err;

public:
    AccountException(const std::string &err) : _err(err) {};
    ~AccountException() throw() {};
    const char *what() const throw()
    {
        return (_err.c_str());
    }
};

#endif