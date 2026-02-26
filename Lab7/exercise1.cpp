#include <iostream>
#include <string>

// 1. 统一声明，全部使用 size_t 比 int 好很多！
bool vabs(int *p, size_t n);
bool vabs(float *p, size_t n);
bool vabs(double *p, size_t n);

int main() {
    // 获取重载函数地址的正确姿势
    std::cout << "Address of vabs(int):   " << (void*)(bool(*)(int*, size_t))vabs << std::endl;
    std::cout << "Address of vabs(float): " << (void*)(bool(*)(float*, size_t))vabs << std::endl;
    
    return 0;
}

// 2. 实现时注意 == 符号
bool vabs(int *p, size_t n) {
    if (p == nullptr) return false; // 修正为 ==
    for (size_t i = 0; i < n; ++i) {
        p[i] = (p[i] < 0) ? -p[i] : p[i];
    }
    return true;
}

// 记得补充 float 和 double 的实现...