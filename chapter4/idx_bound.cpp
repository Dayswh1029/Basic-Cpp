#include<iostream>

int main()
{

    // 数组是不检查边界的！ 可以访问越界不报错！但是我们必须避免！
    int arr1[4]{1,2,3,4};
    int arr2[4];
    // 数组名 退化为地址！
   // arr2=arr1; // 这种赋值是错误的！ 
   for(size_t idx=0;idx<=4;idx++)
   {
    std::cout<<"arr1["<<idx<<"]= "<<arr1[idx]<<"\n";

   }
   
   
    return 0;
}