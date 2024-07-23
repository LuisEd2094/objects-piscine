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

class DestructTest: public ::testing::Test
{
    protected:
    void SetUp() override
    {
        worker = new Worker();
        worker2 = new Worker();
        shovel = new Shovel();
        shovel2 = new Shovel();
        hammer = new Hammer(); 

    }
    void TearDown() override {
        if (worker)
            delete worker;
        if (worker2)
            delete worker2;
        if (shovel)
            delete shovel;
        if (shovel2)
            delete shovel2;
        if (hammer)
            delete hammer;
    }
    Worker* worker;
    Worker* worker2;
    Shovel* shovel;
    Shovel* shovel2;
    Hammer* hammer;
};

TEST_F(DestructTest, destructionWorkerTest)
{
    worker->setTool(shovel);

    delete worker;
    worker = NULL;

    EXPECT_EQ(shovel->worker, nullptr);

    worker2->setTool(hammer);
    worker2->setTool(shovel);

    delete worker2;
    worker2 = NULL;
    
    EXPECT_EQ(hammer->worker, nullptr);
    EXPECT_EQ(shovel->worker, nullptr);

}

TEST_F(DestructTest, destructionToolTest)
{
    worker->setTool(shovel);

    delete shovel;
    shovel = NULL;

    EXPECT_EQ(worker->_tool.size(), 0);

    worker->setTool(hammer);
    worker->setTool(shovel2);

    delete hammer;
    hammer = NULL;
    delete shovel2;
    shovel2 = NULL;
    
    EXPECT_EQ(worker->_tool.size(), 0);


}

TEST_F(WorkerTest, setToolTest)
{
    worker.setTool(&shovel);

    EXPECT_EQ(worker._tool.front(), &shovel);
    EXPECT_EQ(shovel.worker, &worker);

    worker.setTool(&shovel2);


    EXPECT_EQ(worker._tool.front(), &shovel);
    EXPECT_EQ(worker._tool.back(), &shovel2);

    EXPECT_EQ(shovel.worker, &worker);
    EXPECT_EQ(shovel2.worker, &worker);

    worker.setTool(&hammer);

    EXPECT_EQ(worker._tool.front(), &shovel);
    EXPECT_EQ(worker._tool.back(), &hammer);

    EXPECT_EQ(hammer.worker, &worker);
}


TEST_F(WorkerTest, changeHands)
{
    worker.setTool(&shovel);
    worker2.setTool(&shovel);

    EXPECT_EQ(shovel.worker, &worker2);
    EXPECT_EQ(worker._tool.size(), 0);
    EXPECT_EQ(worker2._tool.size(), 1);
    EXPECT_EQ(worker2._tool.front(), &shovel);

    worker2.setTool(&shovel2);
    worker2.setTool(&hammer);
    worker.setTool(&shovel2);

    EXPECT_EQ(shovel.worker, &worker2);
    EXPECT_EQ(shovel2.worker, &worker);
    EXPECT_EQ(hammer.worker, &worker2);
    EXPECT_EQ(worker._tool.size(), 1);
    EXPECT_EQ(worker._tool.front(), &shovel2);

    EXPECT_EQ(worker2._tool.size(), 2);
    EXPECT_EQ(worker2._tool.front(), &shovel);
    EXPECT_EQ(worker2._tool.back(), &hammer);



}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
