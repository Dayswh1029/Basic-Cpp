#include<iostream>
#include<memory>

class B;
class A{

    private:
        int x;
    public:
        std::shared_ptr<B> pb;
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
class B
{
    public:
    //std::shared_ptr<A> pa; // 循环引用 导致 ref_count 不可能为0 ！
        // B里改成
        std::weak_ptr<A> pa;  // 不增加ref_count
        B(){std::cout<<"Constructor B"<<std::endl;}
        ~B()
        {
            std::cout<<"Destructor B"<<std::endl;
        }

};



int main()
{

    std::shared_ptr<A> upA1(new A(1));
    
    std::cout<<"upA1's data: "<<upA1->getA()<<std::endl;

    A* aptr= new A(2);
    std::shared_ptr<A> upA2(aptr);
    std::cout<<"upA2's data: "<<upA2->getA()<<std::endl;

    std::shared_ptr<A> upA3=std::make_shared<A>(3);
    std::cout<<"upA3's data: "<<upA3->getA()<<std::endl;

    std::shared_ptr<A> upA4=upA3;
    std::cout<<"After initializing upA4's data: "<<upA4->getA()<<std::endl;

    upA4=upA2;
    std::cout<<"After assignemnt, upA4's data: "<<upA4->getA()<<std::endl;

    std::shared_ptr<A> spa= std::make_shared<A>();
    std::shared_ptr<B> spb =std::make_shared<B>();
    spa->pb=spb;
    spb->pa=spa;

    return 0;
}