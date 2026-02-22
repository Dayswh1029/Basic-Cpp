#include<iostream>
#include<cstring>

int main()
{
    char rabitt[16]={'P','e','t','e','r'};
    // 字符串的长度！ strlen
    std::cout<<"rabitt: length is "<<strlen(rabitt)<<std::endl;
    char s[3] = {'a','b','c'}; // 打印字符串肯定越越界!直到遇到 \0
    std::cout<<s<<std::endl;




    char bad_pig[9]={'P','e','p','p','a',' ','P','i','g'};// a bad one! 因为i没有“0/”
    

    char good_pig[10]={'P','e','p','p','a',' ','P','i','g','\0'};


    char name[10]={'Y','u','\0','S','0'};
    std::cout<<strlen(name)<<std::endl; // 字符串长度为2 

   





    return 0;
}