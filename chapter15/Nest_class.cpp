#include<iostream>

class Storage
{

    public:
        class Fruit
        {
            std::string name;
            int weight;
            public:
                Fruit(std::string name="", int weight=0):name(name),weight(weight)
                {

                }
                std::string getInfo()
                {
                    return name +", weight "+ std::to_string(weight)+ "kg.";
                }

        };
    private:
        Fruit fruit;
    public:
        Storage(Fruit f)
        {
            this->fruit=f;
        }
        void print()
        {
            std::cout<<fruit.getInfo()<<std::endl;
        }

};

int main()
{
    Storage::Fruit apple("apple",100);
    Storage mystorage(apple);
    mystorage.print();

    return 0;
}