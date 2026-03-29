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

    Mat2<int ,10> t1;
    t1.insert();
    t1.display();

    //
    A<int, float>  d(5,6.5f);
    d.display();

    // 
    MultipleParameters<int, double> obj1(7,7.7,'c');
    std::cout<<"obj1 values: "<<std::endl;
    obj1.printVar();

    MultipleParameters<double, char, bool> obj2(8.8,'a',false);
    std::cout<<"obj2 values: "<<std::endl;
    obj2.printVar();




    return 0;
}