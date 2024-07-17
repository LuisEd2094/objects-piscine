#include <gtest/gtest.h>
#include <Bank.hpp>
#include <Account.hpp>
# include <sstream>

class PreFilledTest: public ::testing::Test
{
    protected:
    void SetUp() override
    {
        bank = new Bank();
        setup_amount = 100;
        acc_1 = bank->createAccount(setup_amount);
        acc_2 = bank->createAccount(setup_amount);

        setup_id_1 = acc_1->getId();
        setup_id_2 = acc_2->getId();

    }
    void TearDown() override {
        delete bank;
    }
    Bank* bank;
    Account * acc_1;
    Account * acc_2;
    Account * acc_3;
    std::size_t setup_id_2;
    std::size_t setup_id_1;
    std::size_t setup_amount;
};

// Define a fixture class for setup and teardown
class BankTest : public ::testing::Test {
protected:
    void SetUp() override {
        bank = new Bank();
    }

    void TearDown() override {
        delete bank;
    }

    Bank* bank;
};

// Test case for account creation
TEST_F(BankTest, TestAccountCreation) {
    // Arrange
    Bank& bankRef = *bank;
    double amount = 100;
    Account * acc = bankRef.createAccount(amount);
    // Act

    EXPECT_NE(acc, nullptr);
    
}

TEST_F(BankTest, TestMaxAccount)
{
    Bank& bankRef = *bank;

    for (int i = 0; i < MAX_ACCOUNTS; ++i)
        EXPECT_NE(bankRef.createAccount(1), nullptr);
    EXPECT_EQ(bankRef.createAccount(1), nullptr);
}


TEST_F(BankTest, TestAccountContent)
{
    Bank& bankRef = *bank;
    std::size_t amount = 100;

    const Account * acc_1 = bankRef.createAccount(amount);
    const Account * acc_2 = bankRef.createAccount(amount);

    std::size_t id_1 =  acc_1->getId();
    std::size_t id_2 = acc_2->getId();



    EXPECT_NE(acc_1, nullptr);
    EXPECT_NE(acc_2, nullptr);
    EXPECT_EQ(bankRef.getAccount(id_1), acc_1);
    EXPECT_EQ(bankRef.getAccount(3), nullptr);

    EXPECT_EQ(acc_1->getId(), id_1);
    EXPECT_EQ(acc_2->getId(), id_2);
    EXPECT_NE(acc_1->getId(), id_2);
    EXPECT_NE(acc_2->getId(), id_1);

    EXPECT_EQ(acc_1->getBalance(), amount * 0.95);
    EXPECT_EQ(acc_2->getBalance(), amount * 0.95);

    EXPECT_TRUE(acc_1->getUsed());
    EXPECT_TRUE(acc_2->getUsed());

    std::ostringstream os;

    os << *acc_1;

    std::string expected_output = "Account id: 1\nAccount balance: 95\nAccount loan: 0\n";
    EXPECT_EQ(os.str(), expected_output);
}

TEST_F(PreFilledTest, TestDelete)
{
    Bank& bankRef = *bank;

    std::size_t temp_id = acc_1->getId();
    bankRef.deleteAccount(acc_1);
    EXPECT_FALSE(acc_1->getUsed());
    EXPECT_TRUE(acc_2->getUsed());

    /*Should use the address of acc_1*/
    Account * acc_3 = bank->createAccount(setup_amount);

    EXPECT_EQ(acc_3, acc_1);
    EXPECT_NE(acc_3->getId(), temp_id);


    temp_id = acc_2->getId();

    bankRef.deleteAccount(acc_2);
    EXPECT_FALSE(acc_2->getUsed());
    
    acc_3 = bank->createAccount(setup_amount);

    EXPECT_EQ(acc_3, acc_2);
    EXPECT_NE(acc_3->getId(), temp_id);

    /*does nothing*/
    acc_3 = NULL;
    bankRef.deleteAccount(acc_3);


    bankRef.giveLoan(acc_1, 1);
    EXPECT_THROW(bankRef.deleteAccount(acc_1), Exception);
}

#define EXCEPTION_MSG "This is my exception"
void throwException()
{
    throw Exception(EXCEPTION_MSG);
}

TEST(ExceptionTest, whatTest)
{
    try
    {
        throwException();
    }
    catch(const Exception& e)
    {
        EXPECT_STREQ(EXCEPTION_MSG, e.what());

    }
}



TEST_F(PreFilledTest, TestDeposit)
{
    Bank& bankRef = *bank;

    bank->deposit(acc_1, 100);
    EXPECT_EQ(acc_1->getBalance(), 95+95);
    /*two accounts with iniatial values of 100*0.05 == 10 + 5 from new deposit*/
    EXPECT_EQ(bank->getLiquidity(), INITIAL_BANK_LIQUIDITY + 5 + 5 + 5 ); 

}

TEST_F(PreFilledTest, TestAccountLoan)
{
    /*2000 is the max if we set it to 10000**/
    EX
    try
    {
        bank->giveLoan(acc_1, 100);
        EXPECT_EQ(acc_1->getLoan(), 100);
        EXPECT_EQ(acc_1->getBalance(), 195);
        bank->giveLoan(acc_1, 100);
        EXPECT_EQ(acc_1->getLoan(), 200);
        EXPECT_EQ(acc_1->getBalance(), 295);
    }
    catch (const Exception & e)
    {
        FAIL() << "Expected no exception, but got: " << e.what() << std::endl;
    }   

    /* this should throw since is waaay more than what we can lend*/
    EXPECT_THROW(bank->giveLoan(acc_2, INITIAL_BANK_LIQUIDITY), Exception);

    try
    {
        bank->giveLoan(acc_1, 1802);
        EXPECT_EQ(acc_1->getLoan(), 2002);
    }
    catch(const std::exception& e)
    {
        FAIL() << "Expected no exception, but got: " << e.what() << std::endl;
    }
    /*Initial liquidity is set to 10000, but we create two accounts with 100 bucks in them, so we get 5 bucks from each, our liquidity is 
        then 10010 and max debt to 20%, so 2002 debt is not acceptable*/
    EXPECT_THROW(bank->giveLoan(acc_2, 1), Exception);

    
}
TEST_F(PreFilledTest, TestPayment)
{
    acc_3 = bank->createAccount(setup_amount);

    bank->giveLoan(acc_1, 100);
    bank->makePayment(acc_1, 95);

    EXPECT_EQ(acc_1->getLoan(), 5);
    EXPECT_EQ(acc_1->getBalance(), 195);

    bank->makePayment(acc_1, 5);
    EXPECT_EQ(acc_1->getLoan(), 0);
    EXPECT_EQ(acc_1->getBalance(), 195);

    bank->giveLoan(acc_2, 100);
    bank->makePayment(acc_2, 100);
    EXPECT_EQ(acc_2->getLoan(), 0);
    EXPECT_EQ(acc_2->getBalance(), 195);

    bank->giveLoan(acc_3, 100);
    bank->makePayment(acc_3, 200);

    EXPECT_EQ(acc_3->getLoan(), 0);
    EXPECT_EQ(acc_3->getBalance(), 290);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
