#include<iostream>


struct Student
{
    char name[10];
    int born;
    bool male;

};

int main()
{
    Student s1={"wang",1989,true};
    std::cout<<s1.name<<std::endl;
    std::cout<<s1.born<<std::endl;
    std::cout<<(s1.male ? "male": "female")<< std::endl;

    return 0;
}