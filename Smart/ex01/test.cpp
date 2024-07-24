#include <gtest/gtest.h>
# include <sstream>
# include <command.hpp>
# include <thuesdayDiscount.hpp>
# include <packageReductionDiscount.hpp>

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


class TestThuesday: public ::testing::Test
{
    protected:
    void SetUp() override
    {
        arts.push_back(article(10, 1, "Tomato"));    
        arts.push_back(article(20, 3, "Potato"));    
        arts.push_back(article(10, 1, "Banana"));
        com = new thuesdayDiscount("Juan", arts);

    }
    void TearDown() override {
        delete com;
    }
    std::list<article> arts;
    thuesdayDiscount* com;
};


class TestPack: public ::testing::Test
{
    protected:
    void SetUp() override
    {
        arts.push_back(article(10, 1, "Tomato"));    
        arts.push_back(article(20, 3, "Potato"));    
        arts.push_back(article(10, 1, "Banana"));
        com = new packageReductionDiscount("Juan", arts);

    }
    void TearDown() override {
        delete com;
    }
    std::list<article> arts;
    packageReductionDiscount* com;
};

TEST_F(TestPack, testThuesdayPrice)
{
    std::size_t res = com->get_total_price();

    EXPECT_EQ(res, com->command::get_total_price());

    arts.push_back(article(150, 1, "Cabagge"));

    packageReductionDiscount* comcom = new packageReductionDiscount("Pan", arts);


    res = comcom->get_total_price();
    EXPECT_EQ(res, comcom->command::get_total_price() - 10);

    delete comcom;

}


TEST_F(TestThuesday, testThuesdayPrice)
{
    std::size_t res = com->get_total_price();

    /*maybe do a system to check the day to check if the discount is being applied?*/
    EXPECT_EQ(res, com->command::get_total_price());
}


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
