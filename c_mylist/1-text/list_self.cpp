// Created by liuqi on 2026/9/29.
#include <iostream>
#include <cassert>
using namespace std;
template <typename T>
struct Seqlist {
private:
    T* data;
    int size ;
    int capacity;
    void expend(int new_capacity)
    {
        assert(new_capacity >= 0 && new_capacity > capacity);//assert是AI给的建议宏，方便找出错位，逻辑上这里可以用if来判断是否合法
        T* new_data = new T [new_capacity];
        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
public:
    Seqlist(int capacity = 10)
    {
        size = 0;
        this->capacity = capacity;
        data = new T [capacity];
    }
    ~Seqlist()
    {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }
    T& operator[](int index)
    {
        assert(index >= 0 && index < size);//同上一个assert
        return data[index];
    }
    void push_back(T value)
    {
        if (size == capacity)
        {
            expend(capacity * 2);
        }
        data[size] = value;
        size++;
    }
    void insert(int pos,T value)
    {
        assert(pos>=0&&pos<=size);
        if (size == capacity)
        {
            expend(capacity * 2);
        }
        for (int i = size-1;i>=pos;i--)
        {
            data[i+1] = data[i];
        }
        data[pos] = value;
        size++;
    }
    void append(Seqlist* seqlist)
    {
        if (seqlist == nullptr)
        {
            return;
        }
        int total = size + seqlist->size;
        if (capacity<total)
        {
            expend(capacity*(total/capacity+1));
        }
        int j=0;
        for (int i = size;i<total;i++)
        {
            data[i] = seqlist->data[j];
            j++;
        }
        size = total;
    }
    bool find(T value)
    {
        for (int i = 0; i < size; ++i)
        {
            if (data[i] == value)
            {
                return true;
            }
        }
        return false;
    }
    void remove(T target)
    {
        int pos = -1;
        for (int i = 0;i<size;i++)
        {
            if (data[i]==target)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            return;
        }
        for (int i = pos;i<size-1;i++)
        {
            data[i] = data[i+1];
        }
        size--;
    }
    void printAll()
    {
        for (int i = 0;i<size;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Seqlist<int>* seqlist = new Seqlist<int>();
    cout<<"先尾插3个"<<endl;
    seqlist->push_back(10);
    seqlist->push_back(20);
    seqlist->push_back(30);
    seqlist->printAll();
    cout<<"最后一个改成40"<<endl;
    (*seqlist)[2] = 40;
    seqlist->printAll();
    seqlist->insert(0,50);
    cout<<"第一个加50"<<endl;
    seqlist->printAll();
    Seqlist<int>* new_seqlist = new Seqlist<int>();
    new_seqlist->push_back(10);
    cout<<"后面加一个只有10的新数组"<<endl;
    seqlist->append(new_seqlist);
    seqlist->printAll();
    delete new_seqlist;
    seqlist->remove(10);
    cout<<"删除10"<<endl;
    seqlist->printAll();
    delete seqlist;
}
