#include<iostream>
int main()
{

    // int n=5;
    // int sum=0; // 一定要初始化！
    // while(n>0)
    // {
    //     sum+=n;
    //     std::cout<<"n= "<<n<<" ";
    //     std::cout<<"sum= "<<sum<<" "; 
    //     n--; // 一定要对n 改变！
    // }

    unsigned int n=5;
    int sum;
    while(n>0)
    {
        sum+=n;
        std::cout<<"n= "<<(n-=2)<<std::endl;
        std::cout<<"sum= "<<sum<<" "; 
        

    }


    return 0;
}