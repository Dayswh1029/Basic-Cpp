#include<iostream>

int main()
{
    // == !=  > < <= >=
    // notice： not 0 is true !
    if(true&&-1)
    {
        std::cout<<"the condition is true"<<std::endl;
    }
    else if(not -2)
    {
        std::cout<<"(!-2) is true ,really?"<<std::endl;

    }
    else
    {
        std::cout<<" false !!!"<<std::endl;
    }



    return 0;

}