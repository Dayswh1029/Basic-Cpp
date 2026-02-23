#include<iostream>


int main()
{

    char str[20];
    std::cout<<"Enter a string: ";
    std::cin.getline(str,20);
    std::cout<<"You entered: "<<str<<std::endl;



    std::cout<<"Enter the other string: ";
    std::cin.getline(str,20);
    std::cout<<"You entered: "<<str<<std::endl;

    return 0;
}