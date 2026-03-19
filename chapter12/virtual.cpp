#include<iostream>
#include<string>

class Person{
    public:
        std::string name;
    Person(std::string n):name(n)
    {
        // 
    }
    virtual void print()=0;
    // void print() 
    // {
    //     std::cout<<"Name: "<<name<<std::endl;
    // }
};

class Person2
{

    public:
        std::string name;
        Person2(std::string n):name(n)
        {

        }
        virtual void print()=0; // 
};

class Student:public Person{

    public:
        std::string id;
        Student(std::string n, std::string i):Person(n),id(i){}
        void print()
        {
            std::cout<<"Name: "<<name;
            std::cout<<". ID: "<<id<<std::endl;
        }
        
        ~Student()
        {

        }

};

void printobject(Person& p)
{
    p.print();
}



int main()
{

    {
        Student stu("wang","2019");
        printobject(stu);
    }
    
    {
        Person * p=new Student("heng","2020");

        p->print();
        delete p;
    }
    return 0;
}
