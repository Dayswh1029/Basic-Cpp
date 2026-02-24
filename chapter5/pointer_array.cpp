#include<iostream>


struct Student{
    char name[5];
    int born;
    bool male;

};

int main()
{
    // 数组指针！
    Student students[128];
    Student* p0=&students[0];
    Student* p1=&students[1];
    Student* p2=&students[2];
    Student* p3=&students[3];
    std::cout<<"the first address: "<<p0<<std::endl;
    std::cout<<"the second address: "<<p1<<std::endl;
    std::cout<<"the third address: "<<p2<<std::endl;
    std::cout<<"the fourth address: "<<p3<<std::endl;

    std::cout<<"the offset:p3-p0= "<<p3-p0<<std::endl;

    // using the pointer 

    char (*pArr)[5] = &students[0].name; // 指向整个 [5] 数组的指针

    p0->born=200;
    p0->male=true;
    p0->name[0]='W';
    p0->name[1]='H';
    // char name[5]  对应的数组！ name 名字 退化为一个指针！ 
    // 利用循环赋值 name
    char newName[5] = "John";  // 注意：字符串字面量有 '\0'，需要5个字符
    for(int i = 0; i < 5; i++) {
        (*pArr)[i] = newName[i];  // pArr是指针，需要解引用
    }
    // 或者用更简洁的方式：
    for(int i = 0; i < 5; i++) {
        pArr[0][i] = newName[i];  // pArr[0] 等价于 *pArr
    }

    // 地址可以当做数组名，来处理！
    Student* sPtr=students; // 退化！ 类型为 Student*

    sPtr[0].born=2001;
    sPtr[1].born=2020;

  //  Student* sPtr2=&students;// error 

    Student(*sPtr3)[128]=&students; // 整个数组的的指针！ 类型 为 Student（*）【128】

    return 0;
}