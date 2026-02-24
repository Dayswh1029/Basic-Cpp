#include<iostream>

struct Student{

    char _name[10];
    int _born;
    bool _male;
};

int main()
{

    // new and delete
    int* p1=new int; // 
    int* p2=new int();
    int* p3=new int(5);
    int* p4=new int{};
    int* p5=new int{5};


    // 结构体或者数组！

    Student* psa1=new Student[16];


    Student* psa2=new Student[16]{{"wang",2020,true},{"Yu",2001,false}};

    //释放
     // 记得释放内存
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete[] psa1;
    delete[] psa2;


    return 0;
}