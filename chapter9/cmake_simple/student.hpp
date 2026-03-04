#pragma once

#include<iostream>
#include<cstring>
// 仅仅是声明 一些函数！
class Student {
    private:
        int _born;
        char _name[20];
        bool _male;
    public:
        Student();
        Student(const char* name,int born, bool male);
        ~Student();
        void Display() const ;
};