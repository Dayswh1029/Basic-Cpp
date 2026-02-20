#include<iostream>
#include<iomanip>

int main(){

    // 数据类型 一定要初始化！ 
    int num1; //没有初始化 
    std::cout<<"num1 = "<<num1<<std::endl; //  打印的随机值！ 因此我们需要初始化！

    int num2=10;
    std::cout<<"num2 = "<<num2<<std::endl;
    // ========================== 怎么初始化
    int a;
    a=100; // 通过赋值初始化！
    int b= 100; // 直接初始化！
    // 新的 标准 
    int  c(200);
    int d{500};
    std::cout<<"c = "<<c<<"========="<<"d = "<<d<<std::endl;

    // 打印保留小数点问题
    float num3= 3.1f;
    // 保留两位
    std::cout<<std::fixed<<std::setprecision(2)<<num3<<"\n";
  









    return 0;
}