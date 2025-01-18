#include <Person/Student.hpp>
#include <Singleton.hpp>
#include <Person/Headmaster.hpp>
#include <Mediator.hpp>

Student::Student(std::string p_name) : Person(p_name),
                                       Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {};
Student::Student(std::string p_name, Room *p_classroom) : Person(p_name, p_classroom),
                                                          Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {};
Student::~Student() {};
void Student::attendClass(Classroom *p_classroom) {
    (void)p_classroom;

};
void Student::exitClass() {};
void Student::graduate(Course *p_course) {
    (void)p_course;
};