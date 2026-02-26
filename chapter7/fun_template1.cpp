#include<iostream>
#include<typeinfo>


template<typename T>
T sum(T x,T y){
    std::cout<<"the input type is "<<typeid(T).name()<<std::endl;
    return x+y;
}


int main()
{

    int result =sum(1,2);



    return 0;
}