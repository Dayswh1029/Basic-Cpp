#include<iostream>
#include<iomanip>


// 输出格式的第二种方法 用iomanip
int main()
{
    std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
    std::cout<<56.8<<std::setw(12)<<std::setfill('#')<<456.77<<std::endl;

    std::cout<<std::left;
    std::cout<<std::setw(12)<<std::setprecision(2)<<123.356<<std::endl;
    std::cout<<std::setw(12)<<std::setprecision(5)<<3897.6784385<<std::endl;

    std::cout<<std::right;
    std::cout<<std::setw(12)<<std::setfill(' ')<<123.356<<std::endl;
    std::cout<<std::setw(12)<<std::setfill(' ')<<3897.6784385<<std::endl;

    std::cout.unsetf(std::ios_base::fixed);
    std::cout<<56.8<<std::setw(12)<<std::setfill('$')<<456.77<<std::endl;

    return 0;
}