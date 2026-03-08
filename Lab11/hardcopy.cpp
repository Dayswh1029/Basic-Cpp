#include<iostream>


// 深拷贝!!hard  copy 
class PtrHardcopy{
    private:
        std::string* ps; // 字符串类型的 指针！！！
        int i;
    public:
        PtrHardcopy(const std::string &s=std::string(),int i):ps(new std::string(s)),i(0)
        {

        }
        PtrHardcopy(const PtrHardcopy& p):i(p.i)
        {
           std::string*  ps= new std::string(*p.ps);

        }
        PtrHardcopy& operator=(const PtrHardcopy& other)
        {
            auto newp =new std::string(*other.ps);
            delete ps;
            ps=newp;
            i=other.i;
            return *this;
        }
        ~PtrHardcopy()
        {
            delete ps;

        }


};




int main()
{
    

    return 0;
}