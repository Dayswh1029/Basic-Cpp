#include<iostream>



int main()
{
    char str[20];
    std::cout<<"Enter a string:";
    std::cin.get(str,20);
    std::cout<<"You entered: "<<str<<std::endl;

    
    std::cin.get(); 
    std::cout<<"Enter the other string:";
    std::cin.get(str,20);
    std::cout<<"You entered: "<<str<<std::endl;
    return 0;
}