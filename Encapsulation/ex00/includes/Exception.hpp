#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <exception>
# include <iostream>

class Exception : public std::exception
{
       private:
        std::string _err;
    public:
        Exception(const std::string& err) : _err(err) {};
        ~Exception() throw() {};
        const char *what() const throw()
        {
            return (_err.c_str());
        } 
};

#endif