#include<iostream>
#include"rational.hpp"



int main()
{
    Rational a=10;
    Rational b(1,2);
    Rational c=a*b;
    std::cout<<"c= "<<c<<std::endl;

    Rational d=2*a;
    std::cout<<"d= "<<d<<std::endl;

    Rational e=b*3;
    std::cout<<"e= "<<e<<std::endl;
    
    Rational f=2*3;
    std::cout<<"f= "<<f<<std::endl;

    return 0;
}