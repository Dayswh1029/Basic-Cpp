#include<iostream>
#include<cmath>

int main()
{
    std::cout<<std::fixed;
    float f1=1.0f;
    std::cout<<"f1= "<<f1<<std::endl;

    float a=0.1f;
    float f2=a+a+a+a+a+a+a+a+a+a;
    std::cout<<"f2= "<<f2<<std::endl;

   // if(f1==f2)
   float epsilon =0.000001f;
    if(std::fabs(f1-f2)<epsilon)
    {
        std::cout<<"f1 == f2"<<std::endl;

    }
    else
    {
        std::cout<<"f1!=f2"<<std::endl;
    }

    return 0;
}