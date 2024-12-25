#include <Aux.hpp>

int main(void)
{
    Bank bank;
    try
    {
        Account *acc = bank.createAccount(100);

        Account *test_account = bank[acc->getId()];
        if (test_account)
        {
            std::cout << "Account found!" << std::endl;
        }
        else
        {
            std::cerr << "Account not found!" << std::endl;
        }

        bank.giveLoan(acc, 100);
        std::cout << *acc << std::endl;
        bank.makePayment(acc, 50);
        std::cout << *acc << std::endl;
        bank.withdraw(acc, 50);
        std::cout << *acc << std::endl;
        std::cout << "Bank liquidity " << bank.getLiquidity() << std::endl;
        if (acc)
        {
            std::cout << *acc << std::endl;
            try
            {
                bank.deleteAccount(acc);
            }
            catch (const Exception &e)
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
    catch (const Exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}