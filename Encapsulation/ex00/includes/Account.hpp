#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

# include <cstddef>


class Bank;
class Account
{
    public:
        /*Account will only be usable through class Bank*/
        ~Account();

    private: 
        /*Only bank is able to create Account Objects*/

        std::size_t _id;
        double      _balance;
        bool        _used;

        Account();
        
        friend class Bank;

};

#endif