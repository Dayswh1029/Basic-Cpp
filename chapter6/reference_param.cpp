#include<iostream>


int foo_ref(int &x)
{
    x+=30;
    return x;
}



int main()
{

    int num=10;
    int& num_ref=num;
    std::cout<<"num= "<<num<<std::endl;

    num_ref=20;
    std::cout<<"num= "<<num<<std::endl; // 通过引用可以改变原始的数值！




    return 0;
}