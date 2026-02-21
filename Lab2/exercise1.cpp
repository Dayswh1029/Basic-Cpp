#include<iostream>

int main()
{
    signed char a=127;
    unsigned char b=0x7f;
    char c=0x7f;
    a=a<<1;
    b=b<<1;
    c=c<<1; 
    std::cout<<"a = "<<(int)a<<std::endl;
    std::cout<<"b = "<<(int)b<<std::endl;
    std::cout<<"c = "<<(int)c<<std::endl;

    std::cout<<">>  move right"<<"\n";
    a=a>>1;
    b=b>>1;
    c=c>>1;
    std::cout<<"a = "<<(int)a<<std::endl;
    std::cout<<"b = "<<(int)b<<std::endl;
    std::cout<<"c = "<<(int)c<<std::endl;

    return 0;
}