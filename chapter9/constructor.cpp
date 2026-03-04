#include<iostream>
#include<cstring>
class Student{
    public:
        Student()
        {
            name[0]=0;
            born=0;
            male=false;
            std::cout<<"Constructor: Student()"<<std::endl;
        }
        Student(const char* initName):born(0),male(true)
        {
            setName(initName);
            std::cout<<"Constructor: Student(const char*)"<<std::endl;
        }
        Student(const char* initName, int initBorn, bool isMale)
        {
            setName(initName);
            born=initBorn;
            male=isMale;
            std::cout<<"Constructor: Student(const char*, int , bool)"<<std::endl;
        }
        void setName(const char* s) 
        {
            if(strlen(s)>=sizeof(name))
            {
                std::cout<<"error: bigger than length of name"<<std::endl;
            }
            strncpy(this->name,s,sizeof(name)-1);
            // 强制补上结束符
            this->name[sizeof(name) - 1] = '\0';
        }
        void setBorn(int b)
        {
           this->born=b;
        }
        void setGender(bool isMale);
        void printInfo();
    private:
        char name[4];
        int born;
        bool male;
};
void Student::setGender(bool isMale)
{
    this->male=isMale;
}
void Student::printInfo()
{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Born on: "<<born<<std::endl;
    std::cout<<"Gender: "<<(male ? "Male": "Female")<<std::endl;
}

int main()
{
    // 无参构造！
    Student s1;
    s1.setName("Yu");
    s1.printInfo();
    s1.setBorn(2000);
    s1.setGender(true);
    s1.printInfo();

    Student s2("Li");
    s2.printInfo();

    Student s3=Student("xu",2000,true);
    s3.printInfo();
    // a question 数组越界了！  
    Student s4=Student("wangheng",2020,false); 
    s4.printInfo();

    return 0;
}