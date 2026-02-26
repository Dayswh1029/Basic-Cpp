#include<iostream>
#include<cmath>


//默认值的位置是需要放到最后一个位置！

// float norm(float x,float y,float z);
// float norm(float x,float y,float z=0);
// float norm(float x,float y=0,float z); // 不要跳

float norm(float x=0,float y=0,float z=0); // 默认的参数设置！


int main()
{

    std::cout<<norm(3.0f)<<std::endl;
    std::cout<<norm(3.0f,4.0f)<<std::endl;
    std::cout<<norm(3.0f,4.0f,5.0f)<<std::endl;

    return 0;
}

float norm(float x,float y,float z)
{


    return sqrt(x*x+y*y+z*z);
}