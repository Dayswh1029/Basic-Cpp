#include<iostream>
#include<cstdlib>
#include<cfloat>
#include<cmath>
float ratio(float a, float b)
{
    if(fabs(a+b)<FLT_EPSILON)
        throw "The sum of thw two arguments is close to zero.";
    return (a-b)/a+b;
}

int main()
{

    float x=0.0f;
    float y=0.0f;
    float z=0.0f;
    std::cout<<"Please input two numbers <q to quit>:";
    while(std::cin>>x>>y)
    {
        // {// try and catch
        //     try
        //     {
        //         z=ratio(x,y);
        //         std::cout<<"ratio("<<x<<", "<< y<<") ="<<z<< std::endl;
        //     }
        //     catch(const char*msg)
        //     {
        //         std::cerr<<"Call ratio() failed: "<<msg<<std::endl;
        //         std::cerr<<"I give you another chance."<<std::endl;

        //     }
        // }


        // 直接杀死程序 ！
         {//non - try and catch
           
            
                z=ratio(x,y);
                std::cout<<"ratio("<<x<<", "<< y<<") ="<<z<< std::endl;
            
          
  
        }

    }

    return 0;
}