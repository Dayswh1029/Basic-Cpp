#include<iostream>
int main()
{
    auto a=10; // auto  a 为 int
    a=20.5;
    a+=10.5;
    std::cout<<a<<std::endl;
    auto b=10.0; // auto b 为double
    b=20.5;
    b+=a;
    std::cout<<b<<std::endl;


    return 0;
}