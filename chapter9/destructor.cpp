#include<iostream>
#include<cstring>
class Student{
    private:
        char* name;
        int born;
        bool male;
    public:
        Student()
        {
            name =new char[1024]{0};
            born=0;
            male=false;
            std::cout<<"Constructor: Student()"<<std::endl;
        }
        Student(const char* initName,int initBorn,bool isMale)
        {
            name=new char[1024]; 
            setName(initName);
            born=initBorn;
            male=isMale;
            std::cout<<"Constructor: Student(const char*)"<<std::endl;

        }
        ~Student()
        {
            std::cout<<"To destroy object: "<<name<<std::endl;
            delete [] name;
            name=nullptr;
        }

        void setName(const char* s)
        {
            strncpy(name,s,1024);
        }
        void setBorn(int born)
        {
            this->born=born;
        }
        // the declaration, the definitions are out of the class!
        void setGender(bool isMale);
        void printInfo();

};
void Student::setGender(bool isMale)
{
    male=isMale;
}
void Student::printInfo()
{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Born on: "<<born<<std::endl;
    std::cout<<"Gender: "<<(male ? "Male": "Female")<<std::endl;
}


int main()
{
    Student yu;
    yu.printInfo();
    yu.setName("wangeng");
    yu.setBorn(2000);
    yu.setGender(true);
    yu.printInfo();

    // 下面是参数构造！
    Student s= Student("wangDays",2000,true); 
    s.printInfo();

    //




    return 0;
}