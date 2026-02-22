#include<iostream>


struct Student1
{
    char name[10];
    int born;
    bool male;

};
struct Student2
{
    int born;
    char name[10];
    bool male;

};

int main()
{
    Student1 s1;
    Student2 s2;
    std::cout<<"Student1 : "<<sizeof(s1)<<std::endl;
    std::cout<<"Student2 : "<<sizeof(s2)<<std::endl;
    
    return 0;
}