#include <iostream>
#include <Course.hpp>
#include <Forms/Form.hpp>
#include <Person/Staff.hpp>


int main()
{
    Course course("Math");
    CourseFinishedForm form(&course);
    CourseFinishedForm form1(&course);
    CourseFinishedForm form2(&course);

    NeedCourseCreationForm form3;
    NeedMoreClassRoomForm form4;
    SubscriptionToCourseForm form5;    
    Headmaster headmaster("Headmaster");

    headmaster.receiveForm(&form);
    headmaster.receiveForm(&form1);
    headmaster.receiveForm(&form2);
    headmaster.receiveForm(&form3);
    headmaster.receiveForm(&form4);
    headmaster.receiveForm(&form5);
    

    headmaster.signForm(&form);
    headmaster.executeForm(&form);

    headmaster.signForm();
    headmaster.executeForm();

    return 0;
}