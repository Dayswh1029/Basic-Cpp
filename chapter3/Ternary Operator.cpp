#include<iostream>
int main()
{

    // 三目运算符！? :
    bool isPositive= true;
    int factor =0;
    if(isPositive)
    {
        factor=1;
    }
    else
    {
        factor =0;
    }
    factor =isPositive ? 1:-1;
    // isPositive is true factor is 1 or factor is -1;
    std::cout<<"factor = "<<factor<<std::endl;



    return 0;

}
