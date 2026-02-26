#include<iostream>

#include<cmath>
float norm_l1(float x, float y);
float norm_l2(float x,float y);
float (&norm_refe)(float,float)=norm_l1;


int main()
{

    
    std::cout<<"L1 norm of (-3,4)= "<<norm_refe(-3,4)<<std::endl;

  


    return 0;
}

float norm_l1(float x,float y)
{
    return fabs(x)+fabs(y);
}

float norm_l2(float x, float y)
{

    return sqrt(x*x+y*y);

}