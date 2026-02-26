#include<iostream>
#include<typeinfo>

template<typename T>
T sum(T x, T y)
{
    std::cout<<"the input type is "<<typeid(T).name()<<std::endl;

    return x+y;
}


 


int main()
{

    //Implicitly instantiates sum<int>(int,int) 强制 显式 int 
    std::cout<<"sum = "<<sum<int>(2.2f,3.0f)<<std::endl;

    std::cout<<"sum = "<<sum(2.2f,3.0f)<<std::endl;


    return 0;
}