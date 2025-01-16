#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <Person/Staff.hpp>
class Headmaster;
class Professor : public Staff, public Mediatee
{
private:
    Course *_currentCourse;
    Professor() : Staff("Professor"), Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {}
void receive(const std::string& event) {
    static_cast<void>(event);};
public:
    void assignCourse(Course *p_course);
    void doClass();
    void closeCourse();
    Professor(std::string p_name) : Staff(p_name), Mediatee(static_cast<Mediator *>(&Singleton<Headmaster>::getInstance())) {}
    ~Professor() {};

};
    

#endif