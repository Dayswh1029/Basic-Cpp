#include<iostream>

class Person
{
    protected:
        std::string name;
    public:
        Person(std::string name=""):name(name){}
        virtual ~Person(){}
        virtual std::string getInfo()
        {
            return name;
        }

};

class Student:public Person
{
    std::string studentid;
    public:
        Student(std::string name="",std::string sid=""):Person(name),studentid(sid){}
        std::string getInfo()
        {
            return name+":"+studentid;
        }

};

int main()
{
    Person  person("Yu");
    Student student("Sam", "20210212");
    Person* pp=&student;
    Person& rp=student;

    Student *ps =(Student*)&person;
    std::cout<<person.getInfo()<<std::endl;
    // danger if  getInfo is not  virtual 

    std::cout<<ps->getInfo()<<std::endl; 
    ps =dynamic_cast<Student*>(&person);
    printf("address=%p\n",ps);
    pp=dynamic_cast<Person*>(&student);
    printf("address= %p\n",pp);

    return 0;
}