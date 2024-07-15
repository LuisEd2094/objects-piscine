#include <Aux.hpp>


int main(void)
{
    Bank bank;

    std::size_t id = bank.createAccount(100);
    if (id != 0)
    {
        Account *account = bank.getAccount(id);
        std::cout << *account << std::endl;
    }
    else
    {
        std::cerr << "The bank is not able to create any new account. Poor bankers wont be getting your money!" << std::endl;
    }
}