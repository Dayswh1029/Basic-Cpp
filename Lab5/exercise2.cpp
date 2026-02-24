#include<iostream>


int main()
{


    int matrix[][4]={1,3,5,7,9,11,13,15,17,19}; // 不够的补零！

    int* p=*(matrix+1);

    p+=3; 

    std::cout<<"*p= "<<*p<<std::endl;
    std::cout<<"*p++= "<<*p++<<std::endl;  // 先打印 再指向！
    std::cout<<"++*p= "<<*(++p)<<std::endl; 

    const char *str="Welcome to programming"; 
    long *q=(long*)str;
    q++;
    char *r=(char*)q;
    std::cout<<r<<std::endl;


    unsigned int num=0xE56AF67;
    unsigned short* pshort=(unsigned short*)&num;
    std::cout<<"*pshort= 0x"<<std::hex<<*pshort<<std::endl;


    return 0;
}