#include <Aux.hpp>


int main(void)
{
    Bank bank;

    Account* acc = bank.createAccount(100);
    if (acc)
    {
        std::cout << *acc << std::endl;
        try 
        {
            bank.deleteAccount(acc);
        }
        catch (const Exception & e)
        {
            std::cout << e.what() << std::endl;
            /*make payment*/
        }
    }
    else
    {
        std::cerr << "The bank is not able to create any new account. Poor bankers wont be getting your money!" << std::endl;
    }
}