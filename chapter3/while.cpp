#include<iostream>
int main()
{
    // while loop 
    int num=10;
    while(num>0)
    {
        std::cout<<"num = "<<num<<std::endl;
        num--;
    }

    // do----while 不管 num2 的输入是多少，肯定是需要先执行一次！
    int num2=10;
    do
    {
        std::cout<<"num2 = "<<num2<<std::endl;
        num2--;
    }while(num2>0);

    return 0;
    
}