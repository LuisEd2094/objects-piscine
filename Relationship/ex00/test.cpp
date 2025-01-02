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
class ToolTest: public ::testing::Test
{
    protected:
    void SetUp() override
    {

    }
    void TearDown() override {
    }
    Shovel shovel;
    Shovel shovel2;
    Hammer hammer;
};


class WorkShopTest: public ::testing::Test
{
    protected:
    void SetUp() override
    {
        workshopShovel = new Workshop(&shovel);
        workshopHammer = new Workshop(&hammer);

    }
    void TearDown() override {
        delete workshopShovel;
        delete workshopHammer;
    }
    Worker worker;
    Shovel shovel;
    Hammer hammer;
    Workshop* workshopShovel;
    Workshop* workshopHammer;

};

class WorkShopDeconstructionTest: public ::testing::Test
{
    protected:
    void SetUp() override
    {
        worker = new Worker();
        shovel = new Shovel();
        shovel2 = new Shovel();
        hammer = new Hammer();
        worker->setTool(hammer);
        worker->setTool(shovel);
        workshopShovel = new Workshop(shovel);
        workshopHammer = new Workshop(hammer);

    }
    void TearDown() override {
        if (workshopShovel)
            delete workshopShovel;
        if (workshopHammer)
            delete workshopHammer;
        if (worker)
            delete worker;
        if (shovel)
            delete shovel;
        if (hammer)
            delete hammer;
        if (shovel2)
            delete shovel2;


    }
    Worker* worker;
    Shovel* shovel;
    Shovel* shovel2;
    Hammer* hammer;
    Workshop* workshopShovel;
    Workshop* workshopHammer;

};

class DestructTest: public ::testing::Test
{
    protected:
    void SetUp() override
    {
        worker = new Worker();
        worker2 = new Worker();
        shovel = new Shovel();
        shovel2= new Shovel();
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



TEST_F(ToolTest, testTools)
{
    EXPECT_EQ(shovel.numberOfUses, 0);
    EXPECT_EQ(hammer.numberOfUses, 0);

    shovel.use();
    EXPECT_EQ(shovel.numberOfUses, 1);
    hammer.use();
    EXPECT_EQ(hammer.numberOfUses, 1);
    hammer.use();
    EXPECT_EQ(hammer.numberOfUses, 2);

}

TEST_F(WorkShopDeconstructionTest, destructWorkers)
{
    workshopShovel->signUp(worker);
    EXPECT_EQ(workshopShovel->_students.size(), 1);
    delete (worker);
    worker = NULL;
    EXPECT_EQ(workshopShovel->_students.size(), 0);
}

TEST_F(WorkShopDeconstructionTest, destructWorkShop)
{
    workshopShovel->signUp(worker);
    EXPECT_EQ(worker->_workshops.size(), 1);
    delete (workshopShovel);
    workshopShovel = NULL;
    EXPECT_EQ(worker->_workshops.size(), 0);
}



TEST_F(WorkShopDeconstructionTest, destructTool)
{
    workshopShovel->signUp(worker);
    EXPECT_EQ(worker->_workshops.size(), 1);
    delete (shovel);
    shovel = NULL;
    EXPECT_EQ(worker->_workshops.size(), 0);
    EXPECT_EQ(workshopShovel->_students.size(), 0);
}


TEST_F(WorkShopDeconstructionTest, destructToolButStillEnough)
{
    workshopShovel->signUp(worker);
    worker->setTool(shovel2);
    EXPECT_EQ(worker->_workshops.size(), 1);
    delete (shovel);
    shovel = NULL;
    EXPECT_EQ(worker->_workshops.size(), 1);
    EXPECT_EQ(workshopShovel->_students.size(), 1);
}



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

    EXPECT_EQ(worker->_tools.size(), 0);

    worker->setTool(hammer);
    worker->setTool(shovel2);

    delete hammer;
    hammer = NULL;
    delete shovel2;
    shovel2 = NULL;
    
    EXPECT_EQ(worker->_tools.size(), 0);
}

TEST_F(WorkerTest, setToolTest)
{
    worker.setTool(&shovel);

    EXPECT_EQ(worker._tools.front(), &shovel);
    EXPECT_EQ(shovel.worker, &worker);

    worker.setTool(&shovel2);


    EXPECT_EQ(worker._tools.front(), &shovel);
    EXPECT_EQ(worker._tools.back(), &shovel2);

    EXPECT_EQ(shovel.worker, &worker);
    EXPECT_EQ(shovel2.worker, &worker);

    worker.setTool(&hammer);

    EXPECT_EQ(worker._tools.front(), &shovel);
    EXPECT_EQ(worker._tools.back(), &hammer);

    EXPECT_EQ(hammer.worker, &worker);
}

TEST_F(WorkerTest, removeToolTest)
{
    worker.setTool(&shovel);

    EXPECT_EQ(worker._tools.front(), &shovel);
    EXPECT_EQ(shovel.worker, &worker);

    worker.resetTool(&shovel2);

    EXPECT_EQ(worker._tools.front(), &shovel);

    worker.resetTool(&shovel);

    EXPECT_EQ(worker._tools.size(), 0);
    EXPECT_TRUE(shovel.worker == NULL);
    
}
TEST_F(WorkerTest, changeHands)
{
    worker.setTool(&shovel);
    worker2.setTool(&shovel);

    EXPECT_EQ(shovel.worker, &worker2);
    EXPECT_EQ(worker._tools.size(), 0);
    EXPECT_EQ(worker2._tools.size(), 1);
    EXPECT_EQ(worker2._tools.front(), &shovel);

    worker2.setTool(&shovel2);
    worker2.setTool(&hammer);
    worker.setTool(&shovel2);

    EXPECT_EQ(shovel.worker, &worker2);
    EXPECT_EQ(shovel2.worker, &worker);
    EXPECT_EQ(hammer.worker, &worker2);
    EXPECT_EQ(worker._tools.size(), 1);
    EXPECT_EQ(worker._tools.front(), &shovel2);

    EXPECT_EQ(worker2._tools.size(), 2);
    EXPECT_EQ(worker2._tools.front(), &shovel);
    EXPECT_EQ(worker2._tools.back(), &hammer);
}


TEST_F(WorkerTest, getShovel)
{
    worker.setTool(&shovel);
    
    EXPECT_EQ(worker.GetTool<Shovel>(), &shovel);

    worker2.setTool(&shovel2);
    worker2.setTool(&shovel);

    EXPECT_EQ(worker.GetTool<Shovel>(), nullptr);
    EXPECT_EQ(worker2.GetTool<Shovel>(), &shovel2);


}

TEST_F(WorkerTest, getHammer)
{
    worker.setTool(&hammer);
    
    EXPECT_EQ(worker.GetTool<Hammer>(), &hammer);

}

TEST_F(WorkerTest, getBoth)
{
    worker.setTool(&hammer);
    worker.setTool(&shovel);
    worker.setTool(&shovel2);

    EXPECT_EQ(worker.GetTool<Hammer>(), &hammer);
    EXPECT_EQ(worker.GetTool<Shovel>(), &shovel);

    EXPECT_EQ(worker2.GetTool<Hammer>(), nullptr);
    EXPECT_EQ(worker2.GetTool<Shovel>(), nullptr);
}



TEST_F(WorkShopTest, addWorkshop)
{
    worker.setTool(&hammer);

    worker.addWorkshop(workshopHammer);
    worker.addWorkshop(workshopShovel);

    EXPECT_EQ(worker._workshops.size(), 1);
    EXPECT_EQ(worker._workshops.front(), workshopHammer);
    EXPECT_EQ(workshopHammer->_students.front(), &worker);
    EXPECT_EQ(workshopHammer->_students.size(), 1);
    EXPECT_EQ(workshopShovel->_students.front(), nullptr);
    EXPECT_EQ(workshopShovel->_students.size(), 0);

    worker.setTool(&shovel);
    worker.addWorkshop(workshopHammer);
    worker.addWorkshop(workshopShovel);
    EXPECT_EQ(worker._workshops.size(), 2);
    EXPECT_EQ(worker._workshops.front(), workshopHammer);
    EXPECT_EQ(worker._workshops.back(), workshopShovel);
    EXPECT_EQ(workshopHammer->_students.front(), &worker);
    EXPECT_EQ(workshopHammer->_students.size(), 1);
    EXPECT_EQ(workshopShovel->_students.front(), &worker);
    EXPECT_EQ(workshopShovel->_students.size(), 1);

}


TEST_F(WorkShopTest, signUp)
{
    worker.setTool(&hammer);

    workshopHammer->signUp(&worker);
    workshopShovel->signUp(&worker);


    EXPECT_EQ(worker._workshops.size(), 1);
    EXPECT_EQ(worker._workshops.front(), workshopHammer);
    EXPECT_EQ(workshopHammer->_students.front(), &worker);
    EXPECT_EQ(workshopHammer->_students.size(), 1);
    EXPECT_EQ(workshopShovel->_students.front(), nullptr);
    EXPECT_EQ(workshopShovel->_students.size(), 0);

    worker.setTool(&shovel);
    workshopHammer->signUp(&worker);
    workshopShovel->signUp(&worker);
    EXPECT_EQ(worker._workshops.size(), 2);
    EXPECT_EQ(worker._workshops.front(), workshopHammer);
    EXPECT_EQ(worker._workshops.back(), workshopShovel);
    EXPECT_EQ(workshopHammer->_students.front(), &worker);
    EXPECT_EQ(workshopHammer->_students.size(), 1);
    EXPECT_EQ(workshopShovel->_students.front(), &worker);
    EXPECT_EQ(workshopShovel->_students.size(), 1);

}


TEST_F(WorkShopTest, signUpAndAddWorkShop)
{
    worker.setTool(&hammer);

    workshopHammer->signUp(&worker);
    worker.addWorkshop(workshopShovel);


    EXPECT_EQ(worker._workshops.size(), 1);
    EXPECT_EQ(worker._workshops.front(), workshopHammer);
    EXPECT_EQ(workshopHammer->_students.front(), &worker);
    EXPECT_EQ(workshopHammer->_students.size(), 1);
    EXPECT_EQ(workshopShovel->_students.front(), nullptr);
    EXPECT_EQ(workshopShovel->_students.size(), 0);

    worker.setTool(&shovel);
    workshopHammer->signUp(&worker);
    worker.addWorkshop(workshopShovel);
    EXPECT_EQ(worker._workshops.size(), 2);
    EXPECT_EQ(worker._workshops.front(), workshopHammer);
    EXPECT_EQ(worker._workshops.back(), workshopShovel);
    EXPECT_EQ(workshopHammer->_students.front(), &worker);
    EXPECT_EQ(workshopHammer->_students.size(), 1);
    EXPECT_EQ(workshopShovel->_students.front(), &worker);
    EXPECT_EQ(workshopShovel->_students.size(), 1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
