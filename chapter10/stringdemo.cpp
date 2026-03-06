#include<iostream>
#include<cstring>
#include<string>

int main()
{
    //string 本身是一个类！！ string class

    std::string s("Hello ");
    s +="C";
    s.operator+=("and CPP");
    std::cout<<s<<std::endl;




    return 0;
}