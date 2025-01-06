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

    list.addStudent(Student("John"));

    for (const auto& student : list.getStudents())
    {
        std::cout << student.getName() << std::endl;
    }
    return 0;
}