#include <iostream>
#include <string>
using namespace std;

struct stuinfo {
    string name;
    int age;
};

template <typename T>
int Compare(const T &a, const T &b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

// stuinfo的特化版本
template <>
int Compare<stuinfo>(const stuinfo &a, const stuinfo &b) {
    // 先按年龄比较
    if (a.age > b.age) return 1;
    if (a.age < b.age) return -1;
    
    // 年龄相同，按名字比较
    if (a.name > b.name) return 1;
    if (a.name < b.name) return -1;
    
    return 0;  // 完全相同
}

int main() {
    // 测试整数
    int i1 = 10, i2 = 20;
    cout << "Compare of the two integers: " << Compare(i1, i2) << endl;
    
    // 测试浮点数
    float f1 = 3.14f, f2 = 2.71f;
    cout << "Compare of the two floats: " << Compare(f1, f2) << endl;
    
    // 测试字符
    char c1 = 'z', c2 = 'a';
    cout << "Compare of the two characters: " << Compare(c1, c2) << endl;
    
    // 测试结构体
    stuinfo s1 = {"Alice", 20};
    stuinfo s2 = {"Bob", 19};
    stuinfo s3 = {"Alice", 20};
    
    cout << "Compare of the two structs (s1 vs s2): " << Compare(s1, s2) << endl;  // s1年龄大，返回1
    cout << "Compare of the two structs (s2 vs s1): " << Compare(s2, s1) << endl;  // s2年龄小，返回-1
    cout << "Compare of the two structs (s1 vs s3): " << Compare(s1, s3) << endl;  // 相同，返回0
    
    return 0;
}