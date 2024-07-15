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

    // Act

    EXPECT_TRUE(bankRef.CreateAccount(100));
    // Assert
    //EXPECT_NE(account.getId(), 1);  // Check that the account ID is not zero
    //EXPECT_EQ(account.getBalance(), 0);  // Check that the initial balance is zero
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
