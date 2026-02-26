#include<iostream>

// 递归函数！

void div2(double val);



int main()
{


    div2(1024.);
    return 0;
}

void div2(double val)
{

    std::cout<<"Entering val = "<<val<<std::endl;
    if(val>1.0)
    {
        div2(val/2);
    }
    else
    {
        std::cout<<"========================================"<<std::endl;
    }
    std::cout<<"Leaving val = "<<val<<std::endl;
}