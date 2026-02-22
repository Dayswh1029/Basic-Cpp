#include<iostream>

int main()
{
    // 介绍一个无符号的整数 size_t 
    // 这是一个非负整数！ 用来 for 循环！

    size_t b=10;
    std::cout<<sizeof(size_t)<<std::endl;
    // 不能n>=0 否则会死循环！ 因为size_t不可能小于0！
    for(size_t n=2;n>0;n--)
    {
        std::cout<<"n= "<<n<<std::endl;
    }

    



    return 0;

}
