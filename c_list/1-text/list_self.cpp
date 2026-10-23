//
// Created by liuqi on 2026/9/29.
//
#include<iostream>
#include<cassert>
using namespace std;
template <typename T>
struct Slist
{
private:
    struct node
    {
        T _val = 0;
        node* _next = nullptr;
        node(T v , node* n = nullptr,node* p = nullptr)
        {
            _val = v;
            _next = n;
        }
    };
    int size = 0;
    node* _head = nullptr;
    node* _tail = nullptr;
    node* _find_node_at(int pos)
    {
        if (pos > size||pos < 0)
        {
            return nullptr;
        }
        node* cur = _head;
        for (int i = 0;i<pos;i++)
        {
            cur = cur->_next;
        }
        return cur;
    }
public:
    void push_front(T v)
    {
        node* t = new node(v);
        if (_head == nullptr)
        {
            _head = t;
            _tail = t;

        }
        else
        {
            t->_next = _head;
            _head = t;
        }
        size++;
    }
    void push_back(T v)
    {
        if (_head == nullptr)
        {
            node* t = new node(v);
            _head = t;
            _tail = t;
            size++;
            return;
        }
        else
        {
            node* t = new node(v);
            _tail->_next = t;
            _tail = t;
            size++;
            return;
        }
    }
    void pop_front()
    {
        if (_head == nullptr)
        {
            return;
        }
        else
        {
            node* t = _head;
            _head = _head->_next;
            size--;
            delete t;
            if (_head == nullptr)
            {
                _tail = nullptr;
            }
        }
    }
    void pop_back()
    {
        if (_head == nullptr)
        {
            return;
        }
        else if (_head == _tail)
        {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
            size--;
            return;
        }
        else
        {
            node* t = _head;
            while (t->_next!=_tail)
            {
                t = t->_next;
            }
            delete _tail;
            _tail = t;
            _tail->_next = nullptr;
            size--;
        }
        
    }
    void print() const
    {
        node* cur = _head;
        while (cur != nullptr)
        {
            cout << cur->_val << " -> ";
            cur = cur->_next;
        }
        cout << "nullptr" << endl;
        cout << "当前长度：" << size << endl;
    }
    void insert_at(T val, int pos)
    {
        if (pos > size||pos < 0)
        {
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        if (pos == size)
        {
            push_back(val);
            return;
        }
        node* prev = _head;
        for (int i = 0; i < pos-1; i++)
        {
            prev = prev->_next;
        }
        node* temp = new node(val, prev->_next);
        prev->_next = temp;
        size++;
    }
};
int main()
{
    slist<int> mylist;

    // 测试尾插
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    cout << "尾插 10、20、30 后：" << endl;
    mylist.print();

    // 测试头插
    mylist.push_front(5);
    mylist.push_front(1);
    cout << "\n头插 5、1 后：" << endl;
    mylist.print();

    return 0;
}