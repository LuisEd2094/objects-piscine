#include <CourseList.hpp>
#include <Course.hpp>
#include <iostream>

Course* CourseList::getCourse(CourseType course_type)
{

    return (find_if([course_type](Course *course)
                   { return course->getType() == course_type; }));
}

CourseList::~CourseList()
{
}