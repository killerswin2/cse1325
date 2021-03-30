#include "person.h"

Person::Person(std::string name, std::string email) : _name{name}, _email{email}{}

/*
    returns the name of the person
*/
std::string Person::to_string()const{
    return _name;
}
/*
    returns the name and email of the person
*/
std::string Person::full_info(){
    return _name + "(" + _email  + ")"; 
}

/*
    overload of stream out operator, only streams out the name 
*/
std::ostream& operator<<(std::ostream& ost, const Person person){
    ost << person.to_string();
    return ost;
}

Person::Person(std::ifstream& ist){
    ist >> _name;
    ist >> _email;

}

void Person::save(std::ofstream& ost){
    ost << _name << std::endl << _email << std::endl;
}