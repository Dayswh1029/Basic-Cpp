#include<iostream>



int main()
{
    int value1=100;
    const int value2=200;
    std::cout<<"value1= "<<value1<<std::endl;
    std::cout<<"value2= "<<value2<<std::endl;

    int * pv1= const_cast<int *>(&value1);
    int * pv2= const_cast<int *>(&value2);

    (*pv1)++;
    (*pv2)++;
    std::cout<<"value1= "<<value1<<std::endl;
    std::cout<<"value2= "<<value2<<std::endl; // 未定义行为 ！ 本身可能已经201 但是打印仍然为200


    int v2= const_cast<int &>(value2);
    v2++;
    std::cout<<"value2= "<<value2<<std::endl; 


    std::cout<<"*pv2 = "<<(*pv2)<<std::endl;
    std::cout<<"v2 = "<<v2<<std::endl;
    



    return 0;
}