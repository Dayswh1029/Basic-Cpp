#include<iostream>
// using the member functions of  ios class 


int main()
{
    std::cout<<56.8<<std::endl;
    std::cout.width(12);
    std::cout.fill('+');
    std::cout<<456.7<<std::endl; // +++++++456.7 12位


    // 设置 有效数字！ 第一个不为零的数字开始计算！
    std::cout.precision(2);
    std::cout<<123.356<<std::endl;
    std::cout.precision(5);
    std::cout<<3897.678485<<std::endl;

    // 设置 小数点之后保留位数
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout<<56.8<<std::endl;
    std::cout.width(12);
    std::cout.fill('*');
    std::cout<<456.77<<std::endl;

    std::cout.precision(2);
    std::cout<<123.356<<std::endl;
    std::cout.precision(5);
    std::cout<<3897.678485<<std::endl;

    // 3 
    bool  flag =true;
    float f=0.20f;
    std::cout.setf(std::ios::showpoint);
    std::cout.setf(std::ios::boolalpha);
    std::cout<<flag<<"\n";
    std::cout<<f<<"\n";

    //4
    std::cout.unsetf(std::ios::boolalpha);
    std::cout.unsetf(std::ios::showpoint); // 这个仍然输出0.20000 因为前面的fixed
    std::cout<<flag<<"\n";
    std::cout<<f<<"\n";

    //5 更简便的

    bool flag2=false;
    double a=2.3876;
    double b=0.46e2;
    std::cout<<std::boolalpha<<flag2<<std::endl;
    std::cout<<std::fixed<<a<<std::endl;
    std::cout<<b<<std::endl;


    std::cout<<std::noboolalpha<<flag2<<std::endl;
    std::cout.unsetf(std::ios::fixed);
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;







    





    return 0;
}