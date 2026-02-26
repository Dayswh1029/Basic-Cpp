#include<iostream>

/*
    函数的重载，不能根据返回值！ 
    可以根据返回类型！

*/
int sum(int x,int y)
{
    std::cout<<"sum(int, int) is called"<<std::endl;
    return x+y;
}

float sum(float x,float y)
{
    std::cout<<"sum(float, float) is called"<<std::endl;
    return x+y;
}

double sum(double x,double y)
{
    std::cout<<"sum(double, double) is called"<<std::endl;
    return x+y;
}


int main()
{

    std::cout<<"sum = "<<sum(1,2)<<std::endl;
    std::cout<<"sum = "<<sum(1.0f,2.0f)<<std::endl;
    std::cout<<"sum = "<<sum(1.1,2.2)<<std::endl;
    //std::cout<<"sum = "<<sum(1,2.2)<<std::endl; // 会产生歧义！ 最好统一 类型



    return 0;
}