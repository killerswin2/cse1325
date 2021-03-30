#ifndef __PARENT_H
#define __PARENT_H
#include "person.h"
#include <vector>


class Student;

class Parent: public Person{
    protected:
        std::vector<Student*> _students;
    public:
        Parent(std::string name, std::string email);
        Parent(std::ifstream& ist);
        virtual void save(std::ofstream& ost);
        void add_student(Student& student);
        int students();
        Student& student(int index);
        std::string full_info() override;
};

#endif