#include<iostream>
#include <cstdint> // 包含 int32_t 和 int8_t 的定义
#include<cmath>
enum color{ WHITE, BLACK, RED, GREEN,BLUE,YELLOW,NUM_COLORS};// 默认从0开始！ 
// NUM_COLORS  默认为6 ！ 可以随着改变！
enum datatype{ TYPE_INT8=1, TYPE_INT16=2, TYPE_INT32=4, TYPE_INT64=8};// 采用了直接赋值！ 
struct Point{
    enum datatype type;
    union{
        // 共享内存！选择 最大的那个！ 而且每次的使用只可以使用一个！不可能同时被用
        std::int8_t data8[3]; // 3*1 
        std::int16_t data16[3];// 3*2
        std::int32_t data32[3];// 3*4
        std::int64_t data64[3]; //3*8=24 ； 这就是最大的内存！ 24bytes！ 

    };
};

size_t datawidth(struct Point pt)
{
    return size_t(pt.type)*3;
}

int64_t l1norm(struct Point pt)  // 1-norm
{
    int64_t result=0;
    switch(pt.type)
    {
        case (TYPE_INT8):
            result =std::abs(pt.data8[0])+std::abs(pt.data8[1])+std::abs(pt.data8[2]);
            break;
        case (TYPE_INT16):
            result =std::abs(pt.data16[0])+std::abs(pt.data16[1])+std::abs(pt.data16[2]);
            break;
        case (TYPE_INT32):
            result =std::abs(pt.data32[0])+std::abs(pt.data32[1])+std::abs(pt.data32[2]);
            break;
        case (TYPE_INT64):
            result =std::abs(pt.data64[0])+std::abs(pt.data64[1])+std::abs(pt.data64[2]);
            break;
        default:
            break;

    }
    return result;

}

int main()
{

    enum color pen_color =RED;
    pen_color=color(3);// convert int to enum
    std::cout<<"we have "<<NUM_COLORS<<" pens."<<std::endl;


    // pen_color +=1; // error
    int  color_index=pen_color;
    color_index +=1;
    std::cout<<"color_index = "<<color_index<<std::endl;

    // declaration and initialization 
    Point point1 = {.type = TYPE_INT8, .data8={-2,3,4}};
    Point point2 = {.type = TYPE_INT32, .data32={1,-2,3}};

    std::cout<<"Data width = "<<datawidth(point1)<<std::endl;
    std::cout<<"Data width = "<<datawidth(point2)<<std::endl;
    
    std::cout<<"L1 norm = "<<l1norm(point1)<<std::endl;
    std::cout<<"L1 norm = "<<l1norm(point2)<<std::endl;
    return 0;

}
