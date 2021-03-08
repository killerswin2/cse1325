#ifndef __PARENT_H
#define __PARENT_H
#include "Person.h"
#include <vector>

class Student;

class Parent: public Person{
    protected:
        std::vector<Student*> students;
    public:
        Parent(std::string name, std::string email);
        void add_student(Student& student);
        int students();
        Student& student(int index);
        std::string full_info() override;
};

#endif