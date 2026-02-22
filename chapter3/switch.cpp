#include<iostream>


int main()
{
    unsigned char input_char=0;
    std::cout<<"Please input a character to start: "<<std::endl;
    std::cin>>input_char;
    while(input_char !='q')
    {
        switch(input_char)
        {

            case 'a':
            case 'A':
                std::cout<<"Move left. Input 'q' to quit."<<std::endl;
                break;
            case 'd':
            case 'D':
                std::cout<<"Move Right. Input 'q' to quit."<<std::endl;
                break;    
            default:
                std::cout<<"Undefined key. Input 'q' to quit."<<std::endl;
                break;

        }

        
    }
    return 0;
}