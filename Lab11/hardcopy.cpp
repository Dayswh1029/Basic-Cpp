#include<iostream>
#include<string>
// 深拷贝!!hard  copy 
class PtrHardcopy{
    private:
        std::string* ps; // 字符串类型的 指针！！！
        int i;
    public:
        PtrHardcopy(){
            this->ps=nullptr;
            std::cout<<"Constructor: Ptrhardcopy()"<<std::endl;
        }
        PtrHardcopy(const std::string & s,int i=0):ps(new std::string(s)),i(0)
        {
            std::cout<<"Constructor: PtrHardcopy( const std::string, int)"<<std::endl;
        }
        // hardcopy constructor 
        PtrHardcopy(const PtrHardcopy & p)
        {
            
           this->ps= new std::string(*(p.ps));
           this->i=p.i;
           std::cout<<"Constructor: PtrHardcopy( cosnt PtrHardcopy& )"<<std::endl;

        }
        // operator = overloading operator = assignment 
        PtrHardcopy& operator=(const PtrHardcopy& other) 
        {
            if(this==&other)
            {
                return *this;

            }
            auto newp =new std::string(*other.ps);
            delete ps;
            ps=newp;
            i=other.i;
            std::cout<<"operator = ()"<<std::endl;
            return *this;
        }
        ~PtrHardcopy()
        {
            delete ps;
        }

};

int main()
{
    PtrHardcopy s("CPP",10);
    PtrHardcopy s1(s);
    PtrHardcopy s2=s1;
    PtrHardcopy s3;
    s3=s1;


    return 0;
}