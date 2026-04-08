#include<iostream>
#include<cstdlib>
#include<cfloat>
#include<cmath>


// try  block 

float ratio(float a, float b)
{
    // throw  抛出   catch  抓住！！！ 
    if(a<0)
        throw 1; 
    if(b<0)
        throw 2;
    if(fabs(a+b)<FLT_EPSILON)
    {
        throw "The sum of the two arguments is closed t ozero.";
    }

    return (a-b)/(a+b);
}


int main()
{

    float x=0.0f;
    float y=0.0f;
    float z=0.0f;
    std::cout<<"Please input two arguments <q to quit>:";
    // 注意 q 输入之后  直接 跳出  while 循环！ 终止 ！ 不是throw  
    while(std::cin>>x>>y)
    {
        try{
            z=ratio(x,y);
            std::cout<<"Ratio("<<x<<","<<y<<") = "<<z<<std::endl;
        }
        catch(const char* msg)
        {
            std::cerr<<"Call ratio() failed: "<<msg<<std::endl;
            std::cerr<<"I give you another chance. "<<std::endl;
        }
        catch(int eid)
        {
            if(eid==1)
            {
                std::cerr<<"Call ratio() failed: the 1st argument should be positive."<<std::endl;
            }
            else if(eid==2)
            {
                std::cerr<<"Call ratio() failed: the 2nd argument should be positive."<<std::endl;
            }
            else{
                std::cerr<<"Call ratio() failed: unrecognized error cide."<<std::endl;
            }
             std::cerr<<"I give you another chance. "<<std::endl;

        }  
        std::cout<<"Please input two numbers<q to quit>:";
    }
    std::cout<<"Bye!!!"<<std::endl;



    return 0;
}