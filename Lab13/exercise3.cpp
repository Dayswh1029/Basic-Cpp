#include<iostream>


// 类 然后 partial  template  specialization !


template<typename Key,typename Value>
class Dictionary
{

    private:
        Key * keys; 
        Value*  values;
        int  size;
        int max_size;
    public:
        Dictionary():keys(),values(),size(),max_size(1)
        {

        }
        Dictionary(Key* key, Value* value):keys(key),values(values)
        {

        }
        Dictionary(int initial_size):size(0)
        {
            max_size=1;
            while(initial_size>=max_size)
            {
                max_size*=2; // 扩容！ capacity 

            }
            keys= new Key[max_size]{};
            values= new Value[max_size]{};
        }
        // 当增加 新的元素，，可能需要扩容！ 
        void add(Key key, Value value)
        {
            Key* tempKey;
            Value* tempVal;
            if(size+1>=max_size)
            {
                max_size*=2;
                tempKey=new Key[max_size];
                tempVal=new Value[max_size];
                for(int i=0;i<size;i++)
                {
                    tempKey[i]=keys[i];
                    tempVal[i]=values[i];

                }
                tempKey[size]=key;
                tempVal[size]=value;
                // 删除 原先的数据！
                delete [] keys;
                delete [] values;
                keys=tempKey;
                values=tempVal;
            }
            else{
                keys[size]=key;
                values[size]=value;
            }
            // 更新 size
            size++;
        }
        void print()
        {
            for(int i=0;i<size;i++)
            {
                std::cout<<"{"<<keys[i]<<", "<<values[i]<<"}"<<std::endl;
            }

        }
        ~Dictionary()
        {
            // 这里我们不应该仅仅 是 delete keys; 而是 数组！ 
            delete[] keys;
            delete[] values;
            keys=nullptr;
            values=nullptr;
        }

};


// partial  specialization 

template<typename Value>
class Dictionary<int,Value>
{
    private:
        int*  keys; 
        Value*  values;
        int  size;
        int max_size;
    public:
        Dictionary(int initial_size):size(0)
        {
            max_size=1;
            while(initial_size>=max_size)
            {
                max_size*=2; // 扩容！ capacity 
            }
            keys= new int[max_size]{};
            values= new Value[max_size]{};
        }
        // 当增加 新的元素，，可能需要扩容！ 
        void add(int key, Value value)
        {
            int* tempKey;
            Value* tempVal;
            if(size+1>=max_size)
            {
                max_size*=2;
                tempKey=new int[max_size];
                tempVal=new Value[max_size];
                for(int i=0;i<size;i++)
                {
                    tempKey[i]=keys[i];
                    tempVal[i]=values[i];

                }
                tempKey[size]=key;
                tempVal[size]=value;
                // 删除 原先的数据！
                delete [] keys;
                delete [] values;
                keys=tempKey;
                values=tempVal;
            }
            else{
                keys[size]=key;
                values[size]=value;
            }
            // 更新 size
            size++;
        }
        void print()
        {
            for(int i=0;i<size;i++)
            {
                std::cout<<"{"<<keys[i]<<", "<<values[i]<<"}"<<std::endl;
            }

        }
        Dictionary& sort() 
         {
            for(int i=0;i<size-1;i++)
            {
                for(int j=0;j<size-1-i;j++)
                {
                    
                    if(keys[j]>keys[j+1])
                    {
                        // 交换 我们应该引用或者地址！！！！

                        Value  tempVal= values[j];
                        values[j]=values[j+1];
                        values[j+1]=tempVal;

                        int tempKey=keys[j];
                        keys[j]=keys[j+1];
                        keys[j+1]=tempKey;
                    }
                }
            }
            return *this;
         }

        ~Dictionary()
        {
            // 这里我们不应该仅仅 是 delete keys; 而是 数组！ 
            delete[] keys;
            delete[] values;
            keys=nullptr;
            values=nullptr;
        }

};

int main()
{

    Dictionary<const char*, const char*> dict(10);
    dict.print();
    dict.add("apple","fruit");
    dict.add("bababa","fruit");
    dict.add("dog","animal");
    dict.print();
    Dictionary<int, const char*> dict2(20);
    dict2.add(100,"apple");
    dict2.add(200,"cat");
    dict2.add(50,"banana");
    dict2.print();
    dict2.sort();
    dict2.print();

    return 0;
}