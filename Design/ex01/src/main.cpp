#include <iostream>
#include <Singleton.hpp>
#include <StudentList.hpp>
#include <Student.hpp>

int main()
{
    StudentList& list = Singleton<StudentList>::getInstance();
    StudentList& list2 = Singleton<StudentList>::getInstance();

    std::cout << &list << std::endl;
    std::cout << &list2 << std::endl;

    list.push_back(Student("John"));

    std::cout << list[0].getName() << std::endl;
    return 0;
}