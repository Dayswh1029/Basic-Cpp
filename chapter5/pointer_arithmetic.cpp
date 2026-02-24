#include<iostream>


#define PRINT_ARRAY(array,n)\
for(int idx=0;idx<(n);idx++)\
    std::cout<<"array["<<idx<<"]="<<(array)[idx]<<std::endl;

int main()
{
    // 指针的偏移计算！
    int numbers[4]={1,2,3,4};
    PRINT_ARRAY(numbers,4)
    int *p=numbers+1; // 0+1 p -> 1
    p++; // p+1; p->2
    std::cout<<"numbers = "<<numbers<<std::endl;
    std::cout<<"p = "<<p<<std::endl;

    *p=100;
    PRINT_ARRAY(numbers,4)

    

    return 0;
}