#include<iostream>

int main()
{

    int num=10;
    int sum=0;
    for(size_t i=0;i<num;++i)
    {
        sum +=i;
        std::cout<<"Line "<<i<<std::endl;



    }
    std::cout<<"sum= "<<sum<<std::endl;


    return 0;
}