#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

# include <cstdio>
# include <iostream>
# include <sstream>


class Bank;
class Account
{
    public:
        /*Account will only be usable through class Bank*/
        ~Account();
        std::size_t getId() const; 
        double      getBalance() const;
        bool        getUsed() const;
        

    private: 
        /*Only bank is able to create Account Objects*/

        std::size_t _id;
        double      _balance;
        bool        _used;

        Account();
        void reset();
        
        friend class Bank;
        friend std::ostream& operator<<(std::ostream&, const Account&);

};

#endif