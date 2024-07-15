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

    std::string expected_output = "Account id: 1";
    EXPECT_EQ(os.str(), expected_output);
}

TEST_F(PreFilledTest, TestDelete)
{
    Bank& bankRef = *bank;

    std::size_t temp_id = acc_1->getId();
    bankRef.deleteAccount(acc_1->getId());
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


}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
