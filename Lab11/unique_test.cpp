#include<iostream>
#include<memory>


class A{

    private:
        int x;
    public:
        A(int a):x(a)
        {
            std::cout<<"Constructor with data:"<<x<<std::endl;

        }
        ~A()
        {
             std::cout<<"Destructor with data:"<<x<<std::endl;

        }
        int getA(){return x;}
};

int main()
{
    // basic 
    // std::unique_ptr<int> up1(new int(9));
    // std::cout<<"up1's constent: "<<*up1<<std::endl;

    // std::unique_ptr<std::string> up2(new std::string("hello, world"));
    // std::cout<<"up2's constent: "<<*up2<<std::endl;

    // std::unique_ptr<std::string> up3= std::make_unique<std::string>("Hello, C++");
    // std::cout<<"up3's constent: "<<*up3<<std::endl;


    // std::unique_ptr<int[]> up4= std::make_unique<int[]>(5);
    // std::cout<<"up4's constent: "<<std::endl;
    // for(int i=0; i<5;i++)
    // {
    //     std::cout<<up4[i]<<" ";  
    // }
    // std::cout<<"\n";


    // float* p= new float[3]{1,2,4};
    // std::unique_ptr<float[]> up5(p);
    // std::cout<<"up5's constent: "<<std::endl;
    //  for(int i=0; i<3;i++)
    // {
    //     std::cout<<up5[i]<<" ";  
    // }
    // std::cout<<"\n";


    // std::unique_ptr<int>up6 =std::move(up1);
    // std::cout<<"up6's constent: "<<*up6<<std::endl;

    std::unique_ptr<A> upA1(new A(1));
    
    std::cout<<"upA1's data: "<<upA1->getA()<<std::endl;

    A* aptr= new A(2);
    std::unique_ptr<A> upA2(aptr);
    std::cout<<"upA2's data: "<<upA2->getA()<<std::endl;

    std::unique_ptr<A> upA3=std::make_unique<A>(3);
    std::cout<<"upA3's data: "<<upA3->getA()<<std::endl;






  




    return 0;
}
