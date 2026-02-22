#include<iostream>
void Printarr(int arr[],int len) // 这里数组 arr[] 退化为指针 int* arr;
{
    for(size_t i=0;i<len;++i)
    {
        std::cout<<arr[i]<<" ";

    }
    std::cout<<"\n";

}
int main()
{
    // 数组个数固定之后就不可以改变！
    int len=1;
    while(len<10){

        int num_arr2[len];// 这里绝对不可以初始化！

        std::cout<<"len= "<<len<<" "
        <<"sizeof(num_arr2)= "<<sizeof(num_arr2)<<std::endl;
        ++len;

    }
    int num_arr[5]={1,2,3,4,0};// 没有生命大小的数组！
    // 打印数组
    Printarr(num_arr,5);

    return 0;
}