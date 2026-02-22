#include<iostream>

int main()
{
    int mat[2][3]={{11,12,13},{14,15,16}};
    for(size_t r=0;r<2;r++)
    {
        for(size_t c=0;c<3;c++)
        {
            std::cout<<mat[r][c]<<" ";
        }
        std::cout<<"\n";
    }
    // 二维数组
    //1. 需要确定列数
    int mat1[][3]={0};
   // int mat2[3][]={0};  
   // 多维数组的传递！
   void init_2d_array(float mat[][3],size_t rows, size_t cols);

    return 0;
}