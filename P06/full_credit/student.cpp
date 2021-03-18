#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade) : Person{name, email}, _grade{grade}{}

/*
    this function add a parent to the vector
*/
void Student::add_parent(Parent& parent){
    _parents.push_back(&parent);
}

/*
    this function returns the size of the vector
*/
int Student::parents(){
    return _parents.size();
}

/*
    this function returns the parent at the index in the vector
*/
Parent& Student::parent(int index){
    return *_parents.at(index);
}

/*
    this function returns the std::string line of all the info needed to print out
*/
std::string Student::full_info(){
    std::string parent_names;
    std::string line;
    for(int i = 0; i < _parents.size(); ++i){
        if(i == _parents.size() - 1){
            parent_names += _parents[i]->to_string();
        }else{
            parent_names +=  _parents[i]->to_string() + ", "; 
        }
    }
    line =  _name + " (" + _email  + ") grade: " + std::to_string(_grade) + " parents: " + parent_names;
    return line; 
}