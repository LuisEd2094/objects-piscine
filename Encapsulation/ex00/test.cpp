#include <gtest/gtest.h>
#include <Bank.hpp>
#include <Account.hpp>

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
    std::size_t account_id = bankRef.CreateAccount(amount);
    // Act

    EXPECT_NE(account_id, 0);
    
}

TEST_F(BankTest, TestMaxAccount)
{
    Bank& bankRef = *bank;

    for (int i = 0; i < MAX_ACCOUNTS; ++i)
        EXPECT_NE(bankRef.CreateAccount(1), 0);
    EXPECT_EQ(bankRef.CreateAccount(1), 0);
}


TEST_F(BankTest, TestGetAccount)
{
    Bank& bankRef = *bank;
    std::size_t amount = 100;

    std::size_t id_1 = bankRef.CreateAccount(amount);
    std::size_t id_2 = bankRef.CreateAccount(amount);

    const Account * acc_1 = bankRef.getAccount(id_1);
    const Account * acc_2 = bankRef.getAccount(id_2);
    const Account * acc_3 = bankRef.getAccount(3);


    EXPECT_NE(acc_1, nullptr);
    EXPECT_NE(acc_2, nullptr);
    EXPECT_EQ(acc_3, nullptr);

    EXPECT_EQ(acc_1->getId(), id_1);
    EXPECT_EQ(acc_2->getId(), id_2);
    EXPECT_NE(acc_1->getId(), id_2);
    EXPECT_NE(acc_2->getId(), id_1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
