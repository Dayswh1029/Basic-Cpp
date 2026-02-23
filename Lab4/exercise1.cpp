#include<iostream>
#include<string.h>

int main()
{

    int cards[]{};
    int hands[4];
    int price[]={2,8,3,7,5,9,'C','D'};

    char direction[4]{'L',82,'U',68};
    char title[]="DeepSeek is an awesome tool";

    std::cout<<"sizeof(cards)= "<<sizeof(cards)<<" ,size of cards[0]= "<<sizeof(cards[0])<<std::endl;
    std::cout<<"sizeof(price)= "<<sizeof(price)<<" ,size of price[0]= "<<sizeof(price[0])<<std::endl;
    std::cout<<"sizeof(direction)= "<<sizeof(direction)<<
    " ,length of direction= "<<strlen(direction)<<std::endl;
    std::cout<<"sizeof(title)= "<<sizeof(title)<<" ,length of title[0]= "<<strlen(title)<<std::endl;





    return 0;
}