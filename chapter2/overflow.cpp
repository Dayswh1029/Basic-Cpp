#include<iostream>

int main()
{
    int a=56789;
    int b=56789;
    int  c=a*b;
    std::cout<<"c= "<<c<<"\n"; // 打印的是有问题的！

    // 改变 数据类型！
    long num1=123456;
    long num2=123456;
    long long num=num1*num2;
    std::cout<<"num = "<<num<<"\n";
    
    





    return 0;
}