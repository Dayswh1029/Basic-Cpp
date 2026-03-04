#include<iostream>
#include"student.hpp"

 Student::Student()
 {

    std::cout<<"constructor"<<std::endl;

 }

 Student::Student(const char* name,int born=0, bool male=true):_born(born),_male(male)
 {
    strncpy(_name,name,sizeof(name)-1);
    _name[sizeof(_name) - 1] = '\0';           // 确保结束符


 }
 void Student::Display() const
 {
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Age: " << _born << std::endl;
    std::cout << "Gender: " << (_male ? "Male" : "Female") << std::endl;


 }
Student::~Student()
{
    std::cout<<"destructor"<<std::endl;

}