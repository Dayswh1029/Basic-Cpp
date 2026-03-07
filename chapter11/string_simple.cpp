#include<iostream>
#include<cstring>


class Mystring{
    private:
        int buf_len;
        char* characters;
    public:
        Mystring(int len=64,const char* data=nullptr):buf_len(len)
        { 
            std::cout<<"Constructor(int char*)"<<std::endl;
            this->characters=nullptr;
            create(buf_len,data);

        }
        // 1， 拷贝构造 自己定义！！！
        Mystring(const Mystring& other)
        {
            if(& other!= nullptr)
            {
                create(other.buf_len,other.characters);
            }
            return;
    
        } 
        // 2, 拷贝赋值  自己定义！！
        Mystring& operator=(const Mystring& other)
        {
            if(this!=&other) //自己赋值自己的检查！
            {
                release();
                create(other.buf_len,other.characters);
            }
            return *this; // 直接返回自己！
             
        }

        ~Mystring()
        {
            release();
            
        }
        // 如果成功返回1 如果失败返回 0！！
        bool create(int buf_len,const char* data)
        {
            release(); 
            // 1，检查数据！安全
            this->buf_len=buf_len;

            if(this->buf_len !=0)
            {
                this->characters= new char[this->buf_len]{};
                if(data){
                    strncpy(this->characters,data,this->buf_len);
                } 
            }
            return true;
        }

        void release()
        {
            delete[] this->characters;
            this->characters=nullptr;
        }
        friend std::ostream& operator<<(std::ostream& os, const Mystring& ms)
        {
            os<<"buf_len = "<<ms.buf_len;
            os<<", characters = "<<static_cast<void*>(ms.characters);
            os<<" ["<<ms.characters<<"]";
            return os;

        }

};



int main()
{

    Mystring str1(10,"Shenzhen"); //
    std::cout<<"str1: "<<str1<<std::endl;
    // 默认拷贝！
    Mystring str2=str1;
    std::cout<<"str2: "<<str2<<std::endl;
    //默认拷贝赋值！！
    Mystring str3;
    std::cout<<"str3: "<<str3<<std::endl;
    str3=str1;
    std::cout<<"str3: "<<str3<<std::endl;

    return 0;
}