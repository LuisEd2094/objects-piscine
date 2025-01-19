#ifndef COURSELIST_HPP
#define COURSELIST_HPP

#include <GenericLists.hpp>  
#include <enums.hpp>
class Course;

class CourseList : public GenericLists<Course *>
{
    public:
    ~CourseList();
    Course *getCourse(CourseType course_type);
};

#endif
