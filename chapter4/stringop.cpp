#include<iostream>
#include<cstring>

int main()
{

    char str1[]="Hello,\0CPP";
    //数组的访问！
    // for(size_t i=0;i<16;i++)
    // {
    //     std::cout<<i<<":"<<+str1[i]<<"("<< str1[i]<<")"<<std::endl;
    // }

    char str2[]="SUSTech";
    char result[128];
    strcpy(result,str1);
    std::cout<<"Result: "<<result<<std::endl;
    strcpy(result,str2); // 覆盖了原来的！
    std::cout<<"Result: "<<result<<std::endl;
    strcat(str1,str2);
    std::cout<<"Str1: "<<str1<<std::endl;
    



    return 0;
}