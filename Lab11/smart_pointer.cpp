#include<iostream>
#include<memory>
// 智能指针 当做 一个类的成员属性！ 
class Stringptr{
    private:
        std::shared_ptr<std::string> data_ptr;
        int i;
    public:
        Stringptr():i(0),data_ptr(nullptr)
        {
            std::cout<<"Constructor Stringptr()"<<std::endl;

        }
        Stringptr(const std::string& s, int m=0)
            :data_ptr(std::make_shared<std::string>(s)),i(m)
            {
                std::cout<<"Constructor Stringptr(const ,int)"<<std::endl;
            }
        
        ~Stringptr(){}
        size_t getRef_count() const
        {
            return data_ptr.use_count();  // shared_ptr 自带！
        }

    friend std::ostream& operator<<(std::ostream& os, const Stringptr& other)
    {
        os << *other.data_ptr << ", "
        << other.i << ", "
        << "ref_count: " << other.data_ptr.use_count();  
        return os;
    }

};


int main()
{
    // 默认构造
    Stringptr s1;
    
    // 有参构造
    Stringptr s2("hello", 10);
    Stringptr s3("world", 20);
    
    // 输出
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    
    // 拷贝构造 → shared_ptr 自动引用计数+1
    Stringptr s4(s2);
    std::cout << "ref_count: " << s2.getRef_count() << std::endl;  // 2
    
    // 赋值
    Stringptr s5;
    s5 = s2;
    std::cout << "ref_count: " << s2.getRef_count() << std::endl;  // 3
    
    {
        Stringptr s6(s2);
        std::cout << "ref_count: " << s2.getRef_count() << std::endl;  // 4
    }   // s6 析构
    
    std::cout << "ref_count: " << s2.getRef_count() << std::endl;  // 回到3 

    return 0;
}