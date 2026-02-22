#include<iostream>

int main()
{

    // 数组
    int arr1[5]; // 没有初始化！
    for(size_t i=0;i<5;i++)
    {
        std::cout<<arr1[i]<<std::endl; //打印随机值！
        
    }

    int arr2[5]={0,1,2,3,4};
    for(size_t i=0;i<5;i++)
    {
        std::cout<<arr2[i]<<std::endl;

    }
    int num_arr1[5]={};
    int num_arr2[5]={0};
    int num_arr3[5]={1,2};
    static int num_arr4[5];// 自动初始化为0





    return 0;
}