#include<iostream>
#include<cstring>
class Student
{
    public:
        void setName(const char* name)
        {
            strncpy(_name,name,sizeof(name)-1);
            _name[sizeof(_name) - 1] = '\0';           // 确保结束符

        }
        void setAge(int age)
        {
            _age=age;
        }
        void setMale(bool sex)
        {
            _male=sex;
        }
        //getName 接口
      // std::string  GetName() const
        const char* GetName() const
        {
            return this->_name; // this 可以省去！
        }

        int GetAge() const{
            return _age;
        }
        bool GetMale() const 
        {
            return _male;
        }
        void   Display() const ; // 仅仅有声明！



    private:
        char _name[20];
        int _age;
        bool _male;

};
    // 打印学生信息的方法
    void Student:: Display() const {
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Age: " << _age << std::endl;
    std::cout << "Gender: " << (_male ? "Male" : "Female") << std::endl;
    }
int main(){
    Student s;
    s.setMale(true); // 函数！
    s.setName("wang");
    std::cout<<s.GetName();
    return 0;
}
// 注意上面的文件可以分开！ .hpp  和 cpp 已经 main.cpp