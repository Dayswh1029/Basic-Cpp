#include<iostream>

int main()
{
    //1.continue 
    int num=10;
    while(num>0)
    {
        if(num==5){
            num--; // 防止进入死循环！
            continue;
        }
        std::cout<<"num= "<<num<<std::endl;
        num--;
    }
    //2,break
    int num2=10;
    while(num2>0)
    {
        if(num2==5){

            break; // break 不会进入死循环！ 直接跳出 while 的循环！
        }
        std::cout<<"num2= "<<num2<<std::endl;
        num2--;
    }

    return 0;
}