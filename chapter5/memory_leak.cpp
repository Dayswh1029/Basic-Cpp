#include<iostream>

void foo()
{

    int* p=(int*)malloc(sizeof(int));
    free(p);
    return;
}


int main()
{
    int* p=NULL;
    p=(int*)malloc(4*sizeof(int));
   // free(p);//

    p=(int*)malloc(8*sizeof(int));
    free(p); //第一个p 肯定被泄露！ 

    foo();



    return 0;
}