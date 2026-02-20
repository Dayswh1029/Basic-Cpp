#include<iostream>
#include<iomanip>


int main()
{
    float f1=1.2f;
    float f2=f1*1000000000000000;// 1.0e15
    std::cout<<std::fixed<<std::setprecision(15)<<f1<<std::endl;
    std::cout<<std::fixed<<std::setprecision(15)<<f2<<std::endl;


    float f3=2.34E10f;
    float  f4=f3+10;
    // 打印 f3 和 f4 
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield); //fixed-Point
    std::cout<<"f3="<<f3<<std::endl;
    std::cout<<"f4="<<f4<<std::endl;
    std::cout<<"f4-f3 ="<<f4-f3<<"\n";

    return 0;
}