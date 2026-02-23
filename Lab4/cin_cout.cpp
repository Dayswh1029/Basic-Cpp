#include<iostream>


int main()
{
    
    char str[100];

    std::cout<<"Enter a string:";
    std::cin>>str; 
    // 注意遇到 空格！ 会当做结束  
    std::cout<<" You entered: "<<str<<std::endl; 

    std::cout<<"Enter the other string:";
    std::cin>>str;
    std::cout<<" You entered: "<<str<<std::endl;

    
    return 0;

}