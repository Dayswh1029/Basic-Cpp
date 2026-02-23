#include<iostream>


union data{

    int n;
    char ch;
    short m;
};

int main()
{

    union data a;
    std::cout<<sizeof(a)<<"; "<<sizeof(data);
    a.n=0x40;
    std::cout<<a.n<<"; "<<a.ch<<"; "<<a.m<<std::endl;

    a.ch='9';
    std::cout<<a.n<<"; "<<a.ch<<"; "<<a.m<<std::endl;

    a.m=0x2059;
    std::cout<<a.n<<"; "<<a.ch<<"; "<<a.m<<std::endl;

    a.n=0x3E25AD54;
    std::cout<<a.n<<"; "<<a.ch<<"; "<<a.m<<std::endl;


    return 0;
}