#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include <fstream>

class Person{
    protected:
        std::string _name;
        std::string _email;
    public:
        Person(std::string name, std::string email);
        Person(std::ifstream& ist);
        virtual void save(std::ofstream& ost);
        std::string to_string()const;
        virtual std::string full_info();
        friend std::ostream& operator<<(std::ostream& ost, const Person person);
};



#endif