#include<iostream>

template<typename T>
class Bag
{

    private:
        T* elem;
        int size;
        int max_size;
    public:
        Bag():elem(nullptr),size(0),max_size(1)
        {
        }
        ~Bag() { delete[] elem; }
        void add(T t)
        {

            T* temp;
            if(size+1>=max_size)
            {
                max_size*=2;
                temp= new T[max_size];
                for(int i=0;i<size;i++)
                {
                    temp[i]=elem[i];
                }
                temp[size++]=t;
                delete[] elem;
                elem=temp;
            }
            else
            {
                elem[size++]=t;
            }
        }
        void print()
        {
            for(int i=0;i<size;i++)
            {
                std::cout<<elem[i]<<" ";
            }
            std::cout<<std::endl;
        }

};

template<typename T>
class Bag<T*>
{
    private:
        T* elem;
        int size;
        int max_size;
    public:
        Bag():elem(0),size(0),max_size(1){}
        ~Bag() { delete[] elem; }
        void add(T* t)
        {
            T* temp;
            if(t==nullptr)
            {
                std::cout<<"Nullptr pointer"<<std::endl;
                return;
            }
              if(size+1>=max_size)
            {
                max_size *=2;
                temp= new T[max_size];
                for(int i=0;i<size;i++)
                {
                    temp[i]=elem[i];
                }
                temp[size++]=*t;
                delete[] elem;
                elem=temp;
            }
            else
            {
                elem[size++]=*t;
            }


        }
        void print()
        {
            for(int i=0;i<size;i++)
            {
                std::cout<<elem[i]<<" ";
            }
            std::cout<<std::endl;
        }


};


int main()
{


    // 测试 1：普通 int 类型的 Bag
    std::cout << "--- Test 1: Bag<int> (General) ---" << std::endl;
    Bag<int> intBag;
    intBag.add(10);
    intBag.add(20);
    intBag.add(30);
    intBag.print(); // 预期输出: 10 20 30

    // 测试 2：指针类型的 Bag<int*>
    std::cout << "\n--- Test 2: Bag<int*> (Partial Specialization) ---" << std::endl;
    Bag<int*> ptrBag;
    
    int x = 100, y = 200, z = 300;
    int* pX = &x;
    int* pY = &y;
    int* pZ = nullptr; // 测试空指针检查

    ptrBag.add(pX);
    ptrBag.add(pY);
    ptrBag.add(pZ); // 会触发 Nullptr 警告
    ptrBag.add(&z); // 直接传地址也可以
    
    std::cout << "Contents of ptrBag (should be values, not addresses):" << std::endl;
    ptrBag.print(); // 预期输出: 100 200 300




    return 0;
}