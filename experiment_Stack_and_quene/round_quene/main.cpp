//created by liuqi on 2026/10/28
#include <iostream>
#include <cassert>
using namespace std;
#define MAX 10//住这里写死了大小，实际上可以存储的大小是MAX-1；
template <typename T>
struct round_quene
{
private:
    T data [MAX];
    int _head = 0;
    int _tail = -1;
    bool is_empty()
    {
        if (_head == (_tail+1)%MAX)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool is_full()
    {
        if (_head ==(_tail +2)%MAX)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    void push_back(T val)
    {
        if (is_full())
        {
            return;
        }
        else
        {
            _tail++;
            _tail = _tail%MAX;
            data[_tail]=val;
        }
    }
    void pop_front ()
    {
        if (is_empty())
        {
            cout<<"队列为空"<<endl;
            return;
        }
        else
        {
            _head++;
            _head = _head%MAX;
        }
    }
    void pointer()
    {
        if (is_empty())
        {
            cout<<"队列为空"<<endl;
            return;
        }
        int i = _head;
        while (i!=(_tail+1)%MAX)
        {
            cout<<data[i]<<" ";
            i = (i+1)%MAX;
        }
        cout<<"\n";
    }
    void clear()//纯自己想的清空方法，应该对，课上没讲
    {
        _head = 0;
        _tail = -1;
    }
    T get_front() const {
        assert(!is_empty() && "空队列不能取队头");
        return data[_head];
    }

};
int main()
{
    round_quene<int> quene;
    cout<<"队列加5,6,7"<<endl;
    quene.push_back(5);
    quene.push_back(6);
    quene.push_back(7);
    quene.pointer();
    quene.pop_front();
    cout<<"头删一下"<<endl;
    quene.pointer();
    cout<<"都删了"<<endl;
    quene.clear();
    cout<<"测试一下没有的情况头删"<<endl;
    quene.pop_front();
}
