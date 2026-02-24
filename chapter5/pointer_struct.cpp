#include<iostream>
struct Student{
    char name[4];
    int born;
    bool male;
};
int main()
{
    Student s; 
    s={"Yu",2002,true};
    Student* stu_ptr1 =&s;
    std::cout<<"the address of struct: "<<stu_ptr1<<std::endl;

    char* stu_ptr2 = stu_ptr1->name;//  数组名的退化！

    char(* ptr_name)[4]=&(stu_ptr1->name); // 获取整个 name 数组的指针！
    // 使用这个指针
    std::cout << "the first char: " << (*ptr_name)[0] << std::endl;  // 'Y'
    std::cout << "the second char: " << (*ptr_name)[1] << std::endl;  // 'u'

    std::cout<<"the address of  name: "<<stu_ptr2<<std::endl;

    std::cout<<"the address of  name: "<<&(stu_ptr1->name)<<std::endl;
    std::cout<<"the address of born: "<<&(stu_ptr1->born)<<std::endl;
    std::cout<<"the address of male: "<<&(stu_ptr1->male)<<std::endl;

    std::cout<<"sizeof(s) = "<<sizeof(s)<<std::endl;
    return 0;

}
