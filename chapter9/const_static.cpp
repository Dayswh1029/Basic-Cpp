#include <iostream>
#include <cstring>

class Student {
private:
    static int totalStudents;        // 学生总数
    static const int MAX_NAME = 50;   // 最大姓名长度
    
    char name[MAX_NAME];
    int born;
    bool male;
    const int id;                     // 每个学生有唯一的 ID
    
public:
    // 构造函数
    Student(const char* initName, int initBorn, bool isMale) 
        : id(++totalStudents) {  // ID 自动递增
        setName(initName);
        born = initBorn;
        male = isMale;
        std::cout << "Constructor: Student(const char* ) " << id << ": " << name << std::endl;
    }
    
    // const 成员函数：只读
    int getBorn() const { return born; }
    bool isMale() const { return male; }
    int getId() const { return id; }
    
    // 静态成员函数：访问静态数据
    static int getTotalStudents() {
        return totalStudents;
    }
    
    // 非 const 成员函数：可以修改
    void setName(const char* s) {
        strncpy(name, s, MAX_NAME - 1);
        name[MAX_NAME - 1] = '\0';
    }
    
    // const 成员函数：保证不修改对象
    void printInfo() const {
        std::cout << "ID: " << id << ", name: " << name 
                  << ", Born: " << born << ", male: " 
                  << (male ? "male" : "femal") << std::endl;
    }
    
    // 析构函数
    ~Student() {
        std::cout << "To destroy student:  #" << id << ": " << name << std::endl;
        totalStudents--;
    }
};

// 初始化静态成员
int Student::totalStudents = 0;

int main() {
    std::cout << "Init: " << Student::getTotalStudents() << std::endl;
    
    Student s1("Tom", 2000, true);
    Student s2("Jerry", 2001, false);
    const Student s3("Alice", 2002, false);  // const 对象
    
    std::cout << "\nStudentInfo: " << std::endl;
    s1.printInfo();
    s2.printInfo();
    s3.printInfo();  //  const 对象调用 const 函数
    
    std::cout << "\nTotal Students: " << Student::getTotalStudents() << std::endl;
    
    // s3.setName("Bob");  // 错误！const 对象不能调用非 const 函数
    
    return 0;
}