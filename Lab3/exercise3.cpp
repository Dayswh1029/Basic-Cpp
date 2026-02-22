#include<iostream>


int main()
{



    int n=1;
    int fa=1;// 需要初始化！ 

    do
    {
        fa*=n;
        n++;


    }while(n<=10);
    std::cout<<"fa= "<<fa<<std::endl;
    return 0;
}