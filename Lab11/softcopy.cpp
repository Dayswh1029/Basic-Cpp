#include<iostream>
#include<string>
class PtrSoftcopy{
    private:
        std::string *ps;
        int i;
        size_t * ref_count;
    public:
        PtrSoftcopy():i(0)
        {
            ps=nullptr;
            *ref_count=1;
            std::cout<<"Constructor： PtrSoftcopy()"<<std::endl;   
        }
        // 有参构造 
        PtrSoftcopy(const std::string & s, int i=0):
            ps(new std::string(s)),i(i),ref_count(new size_t(1))
        {
            std::cout<<"Constructor: PtrSoftcopy(const int size_t)"<<std::endl;

        }
        // 浅 拷贝 但是引入了 计数！！ 
        PtrSoftcopy(const PtrSoftcopy& other)
        {
            this->ps=other.ps;
            this->i=other.i;
            this->ref_count=other.ref_count;
            ++(*ref_count);
            std::cout<<"shallow(soft)  copy "<<std::endl;
        }
        // 赋值 operator=
        PtrSoftcopy& operator=(const PtrSoftcopy& other)
        {
            ++(*other.ref_count);
            if(--*ref_count==0)
            {
                delete ps;
                delete ref_count;
            }
            this->ps=other.ps;
            this->i=other.i;
            ref_count=other.ref_count;
            return *this;

        }
        size_t getRef_count() const
        {
            return *ref_count;
        }
        ~PtrSoftcopy()
        {
            if(--*ref_count==0)
            {
                delete ps;
                delete ref_count;
            }
        }

};


int main()
{
    PtrSoftcopy s1("hello");  
    std::cout << s1.getRef_count()<<"\n";  // 1

    PtrSoftcopy s2(s1);         
    std::cout << s1.getRef_count();  // 2
    std::cout << s2.getRef_count();  // 2

    {
        PtrSoftcopy s3(s1);
        std::cout << s1.getRef_count()<<"\n";  // 3
    }   // s3 destructor 

    std::cout << s1.getRef_count();  // 2



    return 0;
}