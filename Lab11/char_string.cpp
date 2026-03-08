#include<iostream>
#include<cstring>
// 我就想比较 char  and  string 



int main()
{
    char c1 ='A'; // 注意 需要单引号！！
    char c2[]="hello"; // 后面有一个默认的‘\0’
    char* p1= &c1;
    char* p2=c2;
    char* p3=&c2[0];
    *(p2+1);
    *(p3+1);

    char (* p4)[6]= &c2;
    // 使用方式
    std::cout << **p4;        // 输出第一个字符 'h'
    std::cout << (*p4)[0];    // 也是 'h'
    std::cout << (*p4)[1];    // 'e'
    std::cout << *p4;         // 输出整个字符串 "hello"
    // 验证
    std::cout << "=== address ===" << std::endl;
    std::cout << "c1 address : " << (void*)&c1 << std::endl;
    std::cout << "p1 pointer:   " << (void*)p1 << std::endl;
    
    std::cout << "c2 的地址: " << (void*)c2 << std::endl;
    std::cout << "&c2[0]:    " << (void*)&c2[0] << std::endl;
    std::cout << "p2 pointer:   " << (void*)p2 << std::endl;
    std::cout << "p3 pointer:   " << (void*)p3 << std::endl;
    
    std::cout << "\n=== value ===" << std::endl;
    std::cout << "*p1: " << *p1 << std::endl;           // A
    std::cout << "p2: " << p2 << std::endl;              // hello
    std::cout << "*p2: " << *p2 << std::endl;            // h
    std::cout << "p2[1]: " << p2[1] << std::endl;        // e
    std::cout << "*(p2+2): " << *(p2+2) << std::endl;    // l
    
    std::cout << "\n=== compare ! ===" << std::endl;
    std::cout << "sizeof(c2): " << sizeof(c2) << std::endl;  // 6（整个数组）
    std::cout << "sizeof(p2): " << sizeof(p2) << std::endl;  // 8（指针本身）
    // new  空间 
    char * char_new = new char('A');
    char * char2_new= new char[1024]();
    char * char3_new= new char[1024]{};


    delete char_new;
    delete []char2_new;
    delete []char3_new;

    // string  
    std::string s="w";
    std::string s2[3]={"wangheng","hello","Cpp"};
    std::cout<<s2[0][0]<<std::endl; // 输出 w

    std::string * s_ptr=&s;
    std::string* s2_ptr=s2;

    std::string (*s2_ptr2)[3]= &s2;
    std::string * p=&(s2[0]);

    char* char_ptr =(char*)&s;

    // new  string 

    std::string*  new_s1= new std::string("wang");
    std::string*  new_s2= new std::string[12]{};
    std::string*  new_s3= new std::string[12]();

    delete new_s1;
    delete [] new_s2;
    delete [] new_s3;













    return 0;
}
