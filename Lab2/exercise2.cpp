#include<iostream>


int main()
{

    int a=56789;
    int b=23456789;

    int c=a*b;
    std::cout<<"56789*23456789 = "<<c<<std::endl; // overflow

    long long num1=56789;
    long long num2=23456789;
    long long num=num1*num2;
     std::cout<<"num = "<<num<<std::endl;

    return 0;
}
