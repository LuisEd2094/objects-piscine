#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP

#include "List.hpp"  
#include "Student.hpp" 

class StudentList {
public:
    void addStudent(const Student& student) {
        Singleton<List<Student>>::getInstance().addItem(student);
    }

    const std::vector<Student>& getStudents() const {
        return Singleton<List<Student>>::getInstance().getItems();
    }
};

#endif
