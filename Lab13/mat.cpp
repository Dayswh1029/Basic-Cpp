#include<iostream>
#include"mat.hpp"


int main()
{
    int a[MAXSIZE]={1,2,3,4,5};
    Mat<int> m;
    m.setMat(a);
    m.printMat();

    int b[MAXSIZE]{5,4,3,2,1};
    m.addMat(b);
    m.printMat();


    return 0;
}