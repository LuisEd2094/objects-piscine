#include <gtest/gtest.h>
#include <Bank.hpp>
#include <Account.hpp>
# include <sstream>

// Define a fixture class for setup and teardown
class VectorTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
