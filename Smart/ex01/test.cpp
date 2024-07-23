#include <gtest/gtest.h>
# include <sstream>
# include <command.hpp>

class Test: public ::testing::Test
{
    protected:
    void SetUp() override
    {
        arts.push_back(article(10, 1, "Tomato"));    
        arts.push_back(article(20, 3, "Potato"));    
        arts.push_back(article(10, 1, "Banana"));
        com = new command("Juan", arts);

    }
    void TearDown() override {
        delete com;
    }
    std::list<article> arts;
    command* com;
};

TEST_F(Test, testCreation)
{
    EXPECT_NE(&arts, &com->getArticles());
    
    const std::list<article> newList = com->getArticles();

    EXPECT_EQ(newList.front().name, "Tomato");
    EXPECT_EQ(newList.front().price, 10);
    EXPECT_EQ(newList.front().quantity, 1);

    EXPECT_EQ(newList.back().name, "Banana");
    EXPECT_EQ(newList.back().price, 10);
    EXPECT_EQ(newList.back().quantity, 1);

}

TEST_F(Test, testgetPrice)
{
    EXPECT_EQ(com->get_total_price(), 40);

}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
