#include <Person/Student.hpp>
#include <Singleton.hpp>
#include <Person/Headmaster.hpp>
#include <Mediator.hpp>
#include <Lists/StudentList.hpp>
Student::Student(std::string p_name) : Person(p_name),
                                       Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance()))
{
    StudentList studentList;
    studentList.push_back(this);
};
Student::Student(std::string p_name, Room *p_classroom) : Person(p_name, p_classroom),
                                                          Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance()))
{
    StudentList studentList;
    studentList.push_back(this);
};
Student::~Student() {};
void Student::attendClass(ClassRoom *p_classroom)
{
    (void)p_classroom;
};
void Student::exitClass() {};
void Student::graduate(Course *p_course)
{
    (void)p_course;
};