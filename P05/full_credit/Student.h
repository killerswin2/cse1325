#ifndef __STUDENT_H
#define __STUDENT_H
#include "Person.h"
#include <vector>


class Parent;

class Student: public Person{
    protected:
        int grade;
        std::vector<Parent*> parents;
    public:
        Student(std::name, std::string email, int grade);
        void add_parent(Parent& parent);
        int parents();
        Parent& parent(int index);
        std::string full_info() override;
};

#endif