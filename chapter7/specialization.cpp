#include<iostream>
#include<typeinfo>

// 普通模版！
template<typename T>
T sum(T x,T y)
{
    std::cout<<"the input type is "<<typeid(T).name()<<std::endl;

    return x+y;
}
// 特例！ specialization 

struct Point{

    int x;
    int y;
};
// 特例化！
template <>
Point sum<Point>(Point pt1, Point pt2)
{
    Point pt;
    pt.x=pt1.x+pt2.x;
    pt.y=pt1.y+pt2.y;
    return pt;

}


int main()
{
    //explicit instantiated functions
    std::cout<<"sum = "<<sum(1,2)<<std::endl;
    std::cout<<"sum = "<<sum(1.1,2.2)<<std::endl;

    Point pt1{1,2};
    Point pt2{2,3};
    Point pt=sum(pt1,pt2);
    std::cout<<"pt=("<<pt.x<<", "<<pt.y<<")"<<std::endl;

    return 0;
}