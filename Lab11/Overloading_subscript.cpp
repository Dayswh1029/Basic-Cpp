#include<iostream>
#include<cstring>

// #ifndef _MYSTRING_

// #define _MYSTRING_
class String
{

    private:
        char*  m_data;
    public:

        String(  const char* cstr=0)
        {
            create(cstr,strlen(cstr));

            std::cout<<"Constructor: String(const char*)"<<std::endl;

        }
        String(const String& s)
        {
            create(s.m_data,strlen(s.m_data));

        }
        String& operator=(const String& s)
        {

            if(this == &s) return *this;  // 自赋值检查 
            create(s.m_data,strlen(s.m_data));
            return *this;
        }

        char& operator[](size_t i)
        {

            return (this->m_data)[i];
        }
        const char& operator[](size_t i) const{
            return (this->m_data)[i];
        }

        char* get_c_str()const {return m_data;}

        void release()
        {
            delete[] m_data;
            m_data = nullptr;  // 防止野指针 
        }


        bool create(const char* c, size_t i)
        {
            release(); // 释放旧内存！！
            m_data= new char[i+1];
            strcpy(m_data,c);

            return 1;
        }
        ~String()
        {
            release();
        }
    friend std::ostream & operator<<(std::ostream& os , const String& str)
    {
        os << str.m_data << ", "<<std::endl;
        return os;
    }


};



int main()
{

    String s1("Hello");
    const String s2("world");
    std::cout<<"s1[0:]"<<s1[0]<<", s2[0]:"<<s2[0]<<std::endl;
    char a=s1[1];
    char b=s2[2];
    std::cout<<"a: "<<a<<"b: "<<b<<std::endl;

    s1[0]='X';
    // s2[0]='Z';
    std::cout<<"s2: "<<s2<<std::endl;
    std::cout<<"s2: "<<s1<<std::endl;

    std::cout<<"Done: "<<std::endl;


    return 0;
}