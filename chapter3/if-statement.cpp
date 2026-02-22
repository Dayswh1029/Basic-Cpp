#include<iostream>
int main()
{

    int num=10;
    std::cin>>num;
    if(num<5)
        std::cout<<"the number is less than 5"<<std::endl;
    if(num==5)
    {
        std::cout<<"the number is 5"<<"\n";
    }
    else{
        std::cout<<"the number is not 5"<<std::endl;
    }

    return 0;
}