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
    virtual ~Person() {}  // 无论如何加上
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
     //   只有一个 vptr，构造过程中被更新了两次，最终指向 Student 的 vtable
        ~Student() // 子类 会因为 父类 有 virtual 自动加上！！！
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
        // p是Person*，指向Student对象
        // 没有virtual → 只调用~Person()
        // ~Student()不执行 → 资源泄漏
    }
    return 0;
}
// 自己补充一下 vptr 
// vptr（virtual pointer） 是编译器在每个对象内部自动插入的一个指针，指向该对象所属类的虚函数表。
// vtable 是类级别的，不是对象级别的(this)
