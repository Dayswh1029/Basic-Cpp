#include<iostream>

#define PRINT_ARRAY(array,n)\
for(int idx=0;idx<(n);idx++)\
    std::cout<<"array["<<idx<<"]="<<(array)[idx]<<std::endl;


int main()
{

    int numbers[4]={1,2,3,4};
    PRINT_ARRAY(numbers,4)
    
    int *p=numbers;
    p[-1]=2; // out of  bound 
    p[0]=100;
    *(p+1)=200;
    *(p+4)=300; // out of bound
    PRINT_ARRAY(numbers,4)



    return 0;
}