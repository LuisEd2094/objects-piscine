#ifndef STAFF_HPP
#define STAFF_HPP

#include <Person.hpp>

class Form;
class Staff : public Person
{
private:
    Staff() : Person("Staff") {}
public:
    void sign(Form *p_form);
    Staff(std::string p_name) : Person(p_name) {}
};

class Headmaster : public Staff
{
private:
    std::vector<Form *> _formToValidate;
    Headmaster() : Staff("Headmaster") {}
public:
    void receiveForm(Form *p_form);
    Headmaster(std::string p_name) : Staff(p_name) {}
};

class Secretary : public Staff
{
private:
    Secretary() : Staff("Secretary") {}
public:
    Form *createForm(FormType p_formType);
    void archiveForm();
    Secretary(std::string p_name) : Staff(p_name) {}
};

class Professor : public Staff
{
private:
    Course *_currentCourse;
    Professor() : Staff("Professor") {}

public:
    void assignCourse(Course *p_course);
    void doClass();
    void closeCourse();
    Professor(std::string p_name) : Staff(p_name) {}
};

#endif