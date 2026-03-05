#include<iostream>
class Static_test
{
    private:
        static int m_value;
        int normal_value;
    public:
        static int getValue()
        {
           // normal_value=10; 非静态变量，不能被 静态成员函数 操作！
            return m_value;
        }
        int setValue(int v)
        {
            normal_value=v;
            m_value=v; // 可以操作静态变量！

        }
        void display() const
    {
        std::cout << "Static value: " << m_value 
                  << ", normal value: " << normal_value << std::endl;
    }
};

int Static_test::m_value=12; // 初始化为12



int main()
{

     Static_test obj1, obj2;
    
    // 通过对象调用静态成员函数
    std::cout << "obj1: " << obj1.getValue() << std::endl;  // 输出12
    std::cout << "obj2: " << obj2.getValue() << std::endl;  // 输出12
    
    // 通过类名直接调用静态成员函数（推荐方式）
    std::cout << "class: " << Static_test::getValue() << std::endl;  // 输出12
    
    // 修改obj1的普通成员
    obj1.setValue(100);
    obj1.display();  // 静态值: 100, 普通值: 100
    
    // 查看obj2 - 静态成员被改变了，普通成员没变
    obj2.display();  // 静态值: 100, 普通值: 0
    
    // 所有对象共享静态成员
    std::cout << "obj1.getValue(): " << obj1.getValue() << std::endl;  // 100
    std::cout << "obj2.getValue(): " << obj2.getValue() << std::endl;  // 100
    
    return 0;
    
}