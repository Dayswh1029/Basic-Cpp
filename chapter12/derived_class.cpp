#include<iostream>

class Base{
    public:
        int a;
        int b;
    Base(int a=0, int b=0)
    {
        this->a=a;
        this->b=b;
        std::cout<<"Constructor Base::Base("<<a<<","<<b<<")"<<std::endl;
    }
    ~Base()
    {
        
        std::cout<<"Destructor Base::~Base()"<<std::endl;
    }
    int product()
    {
        return a*b;
    }

    friend std::ostream& operator<<(std::ostream& os, const Base & obj)
    {
        os<<"Base: a= "<<obj.a<<", b= "<<obj.b;
        return os;
    }

};

class Derived:public Base{
    public:
        int c;
        Derived(int c):Base(c-2,c-1),c(c)
        {
            this->a+=3;
            std::cout<<"Constructor Derived::Derived ("<<c<<")"<<std::endl;
            
        }
        ~Derived()
        {
            std::cout<<"Destructor Derived::~Derived()"<<std::endl;

        }

        int product()
        {
            return Base::product()*c; //  作用 范围的Product
        }
    
    friend std::ostream& operator<<(std::ostream& os, const Derived & obj)
    {
        // call the friend function in Base class 
        os<<static_cast<const Base&>(obj)<<std::endl; // 强制 转换
        os<<"Derived: C= "<<obj.c;

        return os;
    }


};


int main()
{

    Base base(1,2); // create the obj base 
    std::cout<<base<<std::endl;

    std::cout<<"---------------------------"<<std::endl;
    {
        Derived derived(5);
        std::cout<<derived<<std::endl;
        std::cout<<"Product = "<<derived.product()<<std::endl;

    }

    return 0;
}