#include<iostream>



int main()
{

    int num=1;
    int another=2;

    const int* p1=&num;
   // *p1=20; // 不可以通过 指针p1 来修改 num!


    int* p2=&num;
    *p2=20;


    int* const p3=&num;
    *p3=30; 
    // p3=& another;  不可以再修改！p3!



    return 0;
}