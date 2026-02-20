#include<iostream>

int main()
{

    char c1='C';
    char c2=80; // 十进制   P
    char c3=0x50; // 十六进制  P
    std::cout<<c1<<":"<<c2<<":"<<c3<<std::endl;

     // +c1 直接 转换为 int 数值
    std::cout<<+c1<<":"<<+c2<<":"<<+c3<<std::endl; 


    return 0;
}