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
        node(T v=T() , node* n = nullptr,node* p = nullptr)
        {
            _val = v;
            _next = n;
            _pre = p;
        }
    };
    int size = 0;
    node _head;
    // node* _tail = nullptr;
    node* _find_node_at(int pos)
    {
        if (pos >= size||pos < 0)
        {
            return nullptr;
        }
        node* cur = _head._next;
        for (int i = 0;i<pos;i++)
        {
            cur = cur->_next;
        }
        return cur;
    }
public:
    Dlist()
    {
        _head._next=&_head;
        _head._pre = &_head;
    }
    ~Dlist()
    {
        node *cur = _head._next;
        while(cur!=&_head)
        {
            node* temp = cur;
            cur = cur->_next;
            delete temp;
        }
      }
    void push_front(T v)
    {
        node* t = new node(v);
        node* temp = _head._next;
        _head._next = t;
        t->_pre=&_head;
        t->_next=temp;
        temp->_pre=t;
        size++;
    }
    void push_back(T v)
    {
        node* t = new node(v);
        _head._pre->_next = t;
        t->_pre = _head._pre;
        t->_next = &_head;
        _head._pre = t;
        size++;
    }
    T& read_front()//这里直接返回他本身（别名），不用拷贝，可以修改
    {
        assert(size > 0 && "空链表不能读队头");//上一次实验AI提示使用assert，这次扩展使用一下子，
        // 在报错时打出这句话，提示错误原因
        return _head._next->_val;
    }
    void pop_front()
    {
        if (_head._next==&_head)
        {
            return;
        }
        else
        {
            _head._next->_next->_pre = &_head;
            node* temp = _head._next;
            _head._next = _head._next->_next;
            delete temp;
            size--;
        }
    }
    void pop_back()
    {
        if (&_head == _head._next)
        {
            return;
        }
        _head._pre->_pre->_next=&_head;
        node* temp = _head._pre;
        _head._pre = temp->_pre;
        delete temp;
        size--;
    }
    bool find(T v)
    {
        node* t= &_head;
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
        node* t = _head._next;
        while (t != &_head) {
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
        node* cur = _head._next;
        cout << "头结点" ;
        while (cur != &_head)
        {
            cout << cur->_val << " <-> ";
            cur = cur->_next;
        }
        cout << "头结点" << endl;
        cout << "当前长度：" << size << endl;
    }
    void reverse()
    {
        node* cur = &_head;
        do
        {
            node* t;
            t = cur->_pre;
            cur->_pre = cur->_next;
            cur->_next = t;
            cur=cur->_next;
        }while (cur!=&_head);
    }
};
template <typename T>
struct myStack
{
private:
    Dlist<T> StackList;
    int top = -1;
public:
    void push(T v)
    {
        StackList.push_front(v);
        top++;
    }
    void pop()
    {
        if (top<0)
        {
            return;
        }
        StackList.pop_front();
        top--;
    }
    void clear ()
    {
        while (top>=0)
        {
            StackList.pop_front();
            top--;
        }
    }
    T read_top()
    {
        return StackList.read_front();
    }
    bool is_empty()
    {
        if (top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int get_size()
    {
        return top+1;
    }
};
int main()
{
    myStack<int> int_stack;
    cout<<"判断是否为空\n";
    if (int_stack.is_empty())
    {
        cout<<"为空"<<endl;
    }
    else
    {
        cout<<"不为空"<<endl;
    }
    cout<<"加入3,4,5"<<endl;
    int_stack.push(3);
    int_stack.push(4);
    int_stack.push(5);
    cout<<"读取栈顶"<<endl;
    cout<<int_stack.read_top()<<endl;
    cout<<"弹出栈顶"<<endl;
    int_stack.pop();
    cout<<"读取栈顶"<<endl;
    cout<<int_stack.read_top()<<endl;
    cout<<"栈中元素个数"<<endl;
    cout<<int_stack.get_size()<<endl;

    return 0;
}