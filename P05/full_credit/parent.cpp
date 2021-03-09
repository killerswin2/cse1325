#include "parent.h"
#include "student.h"


Parent::Parent(std::string name, std::string email): Person{name, email} {}

/*
    this function returns the size of the vector
*/
int Parent::students(){
    return _students.size();
}

/*
    this function add a student to the vector
*/
void Parent::add_student(Student& student){
    _students.push_back(&student);
}


/*
    this function returns the student at the index in the vector
*/
Student& Parent::student(int index){
    return *_students.at(index);
}


/*
    this function returns the std::string line of all the info needed to print out
*/
std::string Parent::full_info(){
    std::string student_names;
    std::string line;
    for(int i = 0; i < _students.size(); ++i){
        if(i == _students.size() - 1){
            student_names += _students[i]->to_string();
        }else{
            student_names +=   _students[i]->to_string() + ", "; 
        }
    }
    line =  _name + " (" + _email  + ") " + "parents: " + student_names;
    return line; 
}