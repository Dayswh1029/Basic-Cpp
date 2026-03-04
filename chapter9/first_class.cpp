#include<iostream>
#include<cstring>
class Student{
    public:
    Student()
    {
        std::cout<<"the constructors function"<<std::endl;
    }
    Student( const  char* name,int age=0,bool male=true):_age(age),_male(male)  
    {
        // name 是指针！   如果是 name[] 退化到指针！

        
        //  数组赋值必须用 strncpy
        strncpy(_name, name, 19); 
        _name[19] = '\0'; // 确保安全结束

    }
    ~Student()
    {
        std::cout<<"destructor function;"<<std::endl;
    }

    private:
    char _name[20]; // 数组！   绝对不可以_name =name! 
    int _age;
    bool _male;
};

int main()
{
    Student s{"wang",29,0}; // 需要有参构造！
    Student s2; // 无参构造！ 
    s2=s; // assignment
    
    
    return 0;
}