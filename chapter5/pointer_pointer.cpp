#include<iostream>


int main()
{

    // 指针的指针 pointer -> pointer 
    int num=10;
    int* p1=&num;
    int* *p2=&p1; // p1 的类型为 int*  因此 需要 (int* )*

    *(*p2)=20;
    std::cout<<"num= "<<num<<std::endl;



    return 0;
}