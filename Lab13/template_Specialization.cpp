#include<iostream>
// 特例化  specialization 
// 必须要有 primary  class 
template<typename z>
class Test{
    public:
        Test()
        {
            std::cout<<"it is a general template object. \n";
        }
};
template<>
class Test<int>
{
    public:
        Test()
        {
            std::cout<<"it is a Specialized template object\n";
        }
};


int main()
{
    Test<int> p;
    Test<char> q;
    Test<float> f;


    return 0;
}