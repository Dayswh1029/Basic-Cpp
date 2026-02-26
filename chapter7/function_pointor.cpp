#include<iostream>

#include<cmath>
float norm_l1(float x, float y);
float norm_l2(float x,float y);
float (*norm_ptr)(float,float);


int main()
{

    norm_ptr=norm_l1;
    std::cout<<"L1 norm of (-3,4)= "<<norm_l1(-3,4)<<std::endl;

    norm_ptr=&norm_l2;
    std::cout<<"L2 norm of (-3,4)= "<<(*norm_ptr)(-3.0f,4.0f)<<std::endl;


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