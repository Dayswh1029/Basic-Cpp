#include<iostream>

float arr_sum(const float values[],int len)
{
    // const  防止数组的数据被自己操作修改
    // values[0]=20; // 不可以操作修改 
    float sum=0.0f;
    for(size_t i=0;i<len;++i)
    {
        sum+=values[i];
    }
    return sum;

}

int main()
{

    float values[4]={1.1f,2.2f,3.3f,4.4f};
    float sum=arr_sum(values,4);
    std::cout<<"sum= "<<sum<<std::endl;

    return 0;
}