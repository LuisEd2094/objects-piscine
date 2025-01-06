#ifndef STAFF_HPP
#define STAFF_HPP

#include "Person.hpp"

class Staff : public Person
{
private:
public:
    void sign(Form *p_form);
};

class Headmaster : public Staff
{
private:
    std::vector<Form *> _formToValidate;

public:
    void receiveForm(Form *p_form);
};

class Secretary : public Staff
{
private:
public:
    Form *createForm(FormType p_formType);
    void archiveForm();
};

class Professor : public Staff
{
private:
    Course *_currentCourse;

public:
    void assignCourse(Course *p_course);
    void doClass();
    void closeCourse();
};

#endif