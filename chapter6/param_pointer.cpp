#include<iostream>

int foo1(int x)
{
    x+=10;
    return x;
}

int foo2(int* p)
{
    *p+=20;
    return *p;
}


int main()
{

    int num1=20;
    int result=foo1(num1); // pass by value  传递的是副本！ 

    std::cout<<"the result= "<<result<<std::endl;

    int*p=&num1;
    int result=foo2(p); // pass by pointer 
    std::cout<<"the result= "<<result<<std::endl;



    return 0;
}