#include <iostream>
#include <Singleton.hpp>
#include <StudentList.hpp>
#include <Student.hpp>
#include <RoomList.hpp>
#include <StaffList.hpp>
#include <CourseList.hpp>
#include <Rooms.hpp>
#include <Staff.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <cassert>
#include <chrono>
#include <mutex>

void testSingleton()
{
    std::cout << "Singleton test" << std::endl
              << std::endl;
    StudentList list;
    StudentList list2;
    StudentList list3;


    std::cout << &list << std::endl;
    std::cout << &list2 << std::endl;
    std::cout << &list3 << std::endl;

    list.push_back(Student("John"));

    std::cout << list[0].getName() << std::endl;
    std::cout << list2[0].getName() << std::endl;
    std::cout << list3[0].getName() << std::endl;

}

void testLists()
{
    std::cout << "Lists test" << std::endl
              << std::endl;
    StudentList &studentList = Singleton<StudentList>::getInstance();
    RoomList &roomList = Singleton<RoomList>::getInstance();
    StaffList &staffList = Singleton<StaffList>::getInstance();
    CourseList &courseList = Singleton<CourseList>::getInstance();

    // We already have a Jonh in the list from the last test call
    studentList.push_back(Student("John"));
    studentList.push_back(Student("Jane"));
    studentList.push_back(Student("Jack"));

    roomList.push_back(Room());
    roomList.push_back(Room());
    roomList.push_back(Room());

    staffList.push_back(Staff("Teacher 1"));
    staffList.push_back(Staff("Teacher 2"));
    staffList.push_back(Staff("Teacher 3"));

    courseList.push_back(Course("Math"));
    courseList.push_back(Course("Physics"));
    courseList.push_back(Course("Chemistry"));

    for (size_t i = 0; i < courseList.size(); ++i)
    {
        courseList[i].subscribe(&(studentList[0]));
    }

    for (size_t i = 0; i < courseList.size(); ++i)
    {
        std::cout << courseList[i].getName() << std::endl;
        for (size_t j = 0; j < courseList[i].size(); ++j)
        {
            std::cout << courseList[i][j]->getName() << std::endl;
        };
    }

    for (size_t i = 0; i < studentList.size(); ++i)
    {
        std::cout << studentList[i].getName() << std::endl;
    }

    for (size_t i = 0; i < roomList.size(); ++i)
    {
        std::cout << &(roomList[i]) << std::endl;
    }

    for (size_t i = 0; i < staffList.size(); ++i)
    {
        std::cout << staffList[i].getName() << std::endl;
    }
}

void testListThreadSafety()
{
    const int numThreads = 10;
    const int numItemsPerThread = 1000;

    // A vector to keep track of threads
    std::vector<std::thread> threads;
    std::atomic<int> totalCount(0);

    // Lambda to add items to the list in a thread-safe manner
    auto addItems = [&]()
    {
        for (int i = 0; i < numItemsPerThread; ++i)
        {
            Singleton<List<int>>::getInstance().push_back(i); // Add items to the list
            totalCount++;                                     // Increment the atomic counter
        }
    };

    // Lambda to read items from the list in a thread-safe manner
    auto readItems = [&]()
    {
        for (int i = 0; i < numItemsPerThread; ++i)
        {
            Singleton<List<int>>::getInstance()[i];
        }
    };

    // Launch threads to add items to the list
    for (int i = 0; i < numThreads; ++i)
    {
        threads.push_back(std::thread(addItems));
    }

    // Launch threads to read from the list
    for (int i = 0; i < numThreads; ++i)
    {
        threads.push_back(std::thread(readItems));
    }

    // Wait for all threads to finish
    for (auto &t : threads)
    {
        t.join();
    }

    // After all threads finish, we can check the size of the list
    int expectedCount = numThreads * numItemsPerThread;
    int actualCount = Singleton<List<int>>::getInstance().size();

    // Check if the number of items added is correct
    assert(actualCount == expectedCount);

    // Optionally, print the final size of the list
    std::cout << "Expected number of items: " << expectedCount << std::endl;
    std::cout << "Actual number of items: " << actualCount << std::endl;
    std::cout << "Test passed: Thread-safety is confirmed!" << std::endl;
}

int main()
{
    testSingleton();
    testLists();
    testListThreadSafety();
    return 0;
}