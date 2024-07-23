#include <gtest/gtest.h>
# include <sstream>

class Test: public ::testing::Test
{
    protected:
    void SetUp() override
    {

    }
    void TearDown() override {
    }
};

TEST_F(Test, test)
{

}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
