#include<iostream>


int main()
{

    int a=0;
    int b=0;
    int c=0;
    std::cout<<&a<<std::endl;
    std::cout<<&b<<std::endl;
    std::cout<<&c<<std::endl;


    // 开辟内存 ！ c- allocate

    int * p1=(int*) malloc(4); // 开辟 4个 字节！  类型的空间 
    int * p2=(int*) malloc(4);
    int * p3=(int*) malloc(4);
    std::cout<<p1<<std::endl;
    std::cout<<p2<<std::endl;
    std::cout<<p3<<std::endl;

    free(p1);
    free(p2);
    free(p3);

    return 0;


}