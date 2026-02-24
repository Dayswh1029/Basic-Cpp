#include<iostream>


int main()
{

    int numbers1[]={2,4,6,8,10};

    int(* ptr1)[]=&numbers1; // 没有指定大小！

    int sum=0;
    int* p1=&numbers1[1];
    std::cout<<"the address of the numbers1: "<<numbers1<<std::endl;
    std::cout<<"the address of second element: "<<p1<<std::endl;
    for(int i=0;i<3;i++)
    {
        sum+=*(p1+i);

    }
    std::cout<<"the sum: "<<sum<<std::endl;


    int numbers2[5]={1,2,3,4,5};

    //int(* ptr)[5]=&numbers2;

    int* p2=(int*)(&numbers2+1);

    std::cout<<"the address of the numbers2: "<<numbers2<<std::endl;
    std::cout<<"the address of firth element: "<<(numbers2+4)<<std::endl;

    std::cout<<"p2= "<<p2<<std::endl;
    std::cout<<"the address of second element: "<<(numbers2+1)<<std::endl;
    std::cout<<"*(p2-1)= "<<*(p2-1)<<std::endl;

    return 0;
}