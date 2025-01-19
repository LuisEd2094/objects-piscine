#include <CourseList.hpp>
#include <Course.hpp>
#include <iostream>


CourseList::~CourseList() {
    for (auto course : *this) {
        delete course;
    }
}