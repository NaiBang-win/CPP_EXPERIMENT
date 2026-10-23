//
// Created by liuqi on 2026/10/16.
//
#include<iostream>
#include <assert.h>
using namespace std;
template <typename T>
struct Dlist
{
private:
    struct node
    {
        T _val;
        node* _next = nullptr;
        node* _pre = nullptr;
        node(T v , node* n = nullptr,node* p = nullptr)
        {
            _val = v;
            _next = n;
            _pre = p;
        }
    };
    int size = 0;
    node* _head;
    // node* _tail = nullptr;
    node* _find_node_at(int pos)
    {
        if (pos >= size||pos < 0)
        {
            return nullptr;
        }
        node* cur = _head->_next;
        for (int i = 0;i<pos;i++)
        {
            cur = cur->_next;
        }
        return cur;
    }
public:
    Dlist()
    {
        _head = new node(T(),nullptr,nullptr);
        _head->_next=_head;
        _head->_pre = _head;
    }
    ~Dlist()
    {
        node *cur = _head->_next;
        while(cur!=_head)
        {
            node* temp = cur;
            cur = cur->_next;
            delete temp;
        }
        delete _head;
      }
    void push_front(T v)
    {
        node* t = new node(v);
        node* temp = _head->_next;
        _head->_next = t;
        t->_pre=_head;
        t->_next=temp;
        temp->_pre=t;
        size++;
    }
    void push_back(T v)
    {
        node* t = new node(v);
        _head->_pre->_next = t;
        t->_pre = _head->_pre;
        t->_next = _head;
        _head->_pre = t;
        size++;
    }
    void pop_front()
    {
        if (_head->_next==_head)
        {
            return;
        }
        else
        {
            _head->_next->_next->_pre = _head;
            node* temp = _head->_next;
            _head->_next = _head->_next->_next;
            delete temp;
            size--;
        }
    }
    void pop_back()
    {
        if (_head == _head->_next)
        {
            return;
        }
        _head->_pre->_pre->_next=_head;
        node* temp = _head->_pre;
        _head->_pre = temp->_pre;
        delete temp;
        size--;
    }
    bool find(T v)
    {
        node* t= _head;
        for (int i=0;i<size;i++)
        {
            t = t->_next;
            if (t->_val==v)
            {
                return true;
            }
        }
        return false;
    }
    void insert_at_pre(T val, int pos)
    {
        assert(pos<size&&pos>=0);
        node* t = new node(val);
        node*  a= _find_node_at(pos);
        node* temp = a->_pre;
        temp->_next = t;
        t->_pre=temp;
        t->_next=a;
        a->_pre=t;
        size++;
    }
    void insert_at_next(T val, int pos)
    {
        assert(pos<size&&pos>=0);
        node* t = new node(val);
        node*  a= _find_node_at(pos);
        node* temp = a->_next;
        a->_next = t;
        temp->_pre=t;
        t->_next=temp;
        t->_pre=a;
        size++;
    }
    void remove(T val)
    {
        node* t = _head->_next;
        while (t != _head) {
            if (t->_val == val)
            {
                t->_pre->_next = t->_next;
                t->_next->_pre = t->_pre;
                delete t;
                size--;
                return ;
            }
            t = t->_next;
        }
        return ;
    }
    void print() const
    {
        node* cur = _head->_next;
        cout << "头结点" ;
        while (cur != _head)
        {
            cout << cur->_val << " <-> ";
            cur = cur->_next;
        }
        cout << "头结点" << endl;
        cout << "当前长度：" << size << endl;
    }
    void reverse()
    {
        node* cur = _head;
        do
        {
            node* t;
            t = cur->_pre;
            cur->_pre = cur->_next;
            cur->_next = t;
            cur=cur->_next;
        }while (cur!=_head);
    }
};
int main()
{
    Dlist<int> Dlist;

    cout << "=== 尾插 10、20、30 ===" << endl;
    Dlist.push_back(10);
    Dlist.push_back(20);
    Dlist.push_back(30);
    Dlist.print();

    cout << "\n=== 头插 5、1 ===" << endl;
    Dlist.push_front(5);
    Dlist.push_front(1);
    Dlist.print();

    cout << "\n=== 在在第4个位置之前插入15 ===" << endl;
    Dlist.insert_at_pre(15, 3);
    Dlist.print();

    cout << "\n=== 删除元素10 ===" << endl;
    Dlist.remove(10);
    Dlist.print();

    cout << "\n=== 尾删一次 ===" << endl;
    Dlist.pop_back();
    Dlist.print();

    cout << "\n=== 反转链表 ===" << endl;
    Dlist.reverse();
    Dlist.print();

    return 0;
}