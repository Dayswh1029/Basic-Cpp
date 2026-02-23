#include<iostream>



int main()
{
    int num=10;

    int* ptr=NULL; // 初始化！
    int* ptr2=NULL;

    ptr=&num;    // 赋值 take the address of num, assign to ptr;
    ptr2=&num;
    std::cout<<"the address of num: "<<ptr<<std::endl;
    std::cout<<"the address of num: "<<ptr2<<std::endl; 

    // assign to num
    *ptr=20; // 通过解 引用！赋值！
    std::cout<<"num: "<<num<<std::endl;

    *ptr2=30;
    std::cout<<"num: "<<num<<std::endl;

    return 0;

}