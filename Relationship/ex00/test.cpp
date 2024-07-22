#include <gtest/gtest.h>
#include <Hammer.hpp>
#include <Shovel.hpp>
#include <Tool.hpp>
#include <Worker.hpp>
#include <Workshop.hpp>

# include <sstream>

class WorkerTest: public ::testing::Test
{
    protected:
    void SetUp() override
    {

    }
    void TearDown() override {
    }
    Worker worker;
    Worker worker2;
    Shovel shovel;
    Shovel shovel2;
    Hammer hammer;
};

class ShovelTest: public ::testing::Test
{
    protected:
    void SetUp() override
    {

    }
    void TearDown() override {
    }

};


TEST_F(WorkerTest, destructionWorkerTest)
{
    worker.setTool(&shovel);

    worker.~Worker();

    EXPECT_EQ(shovel.worker, nullptr);

    worker.setTool(&hammer);

    worker.~Worker();
    
    EXPECT_EQ(hammer.worker, nullptr);

}

TEST_F(WorkerTest, destructionToolTest)
{
    worker.setTool(&shovel);

    shovel.~Shovel();

    EXPECT_EQ(worker._tool, nullptr);

    worker.setTool(&hammer);
    hammer.~Hammer();
    
    EXPECT_EQ(worker._tool, nullptr);


}

TEST_F(WorkerTest, setToolTest)
{
    worker.setTool(&shovel);

    EXPECT_EQ(worker._tool, &shovel);
    EXPECT_EQ(shovel.worker, &worker);

    worker.setTool(&shovel2);


    EXPECT_EQ(worker._tool, &shovel2);
    EXPECT_EQ(shovel.worker, nullptr);
    EXPECT_EQ(shovel2.worker, &worker);

    worker.setTool(&shovel2);

    EXPECT_EQ(worker._tool, &shovel2);
    EXPECT_EQ(shovel.worker, nullptr);
    EXPECT_EQ(shovel2.worker, &worker);

    worker2.setTool(&shovel2);

    EXPECT_EQ(worker._tool, nullptr);
    EXPECT_EQ(shovel2.worker, &worker2);
    EXPECT_EQ(worker2._tool, &shovel2);

    worker2.setTool(&hammer);

    EXPECT_EQ(worker2._tool, &hammer);
    EXPECT_EQ(hammer.worker, &worker2);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
