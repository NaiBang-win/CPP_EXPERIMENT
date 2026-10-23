#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d = 0, Node *p = nullptr){
        data = d;
        next = p;
    }
};

struct List{
private:
    Node* head = nullptr;
    unsigned int size = 0;
public:
    int get_size() const
    {
        return size;
    }

    ~List(){
        for(Node *t = head; t != nullptr;){
            t = t->next;
            delete head;
            head = t;
        }
        size = 0;
    }

    void push_front(int d)
    {
        Node *t = new Node(d);
        t->next = head;
        head = t;
        size++;
    }

    void push_back(int d){
        if(head == nullptr){
            push_front(d);
            return;
        }
        Node *t = head;
        while(t->next != nullptr)
            t = t->next;
        t->next = new Node(d);
        size++;
    }

    void pop_front()
    {
        if(head == nullptr){
            return;
        }
        Node *t = head;
        head = head->next;
        delete t;
        size--;
    }

    void pop_back()
    {
        if (head == nullptr) return;
        if (head->next == nullptr){
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node *t = head;
        while (t->next->next != nullptr) t = t->next;
        delete t->next;
        t->next = nullptr;
        size--;
    }

    void printAll() const{
        for(Node *t = head; t != nullptr; t = t->next)
            cout << t->data << " ";
        cout << "\n";
    }

    int count(int target) const
    {
        int cnt = 0;
        Node* cur = head;
        while(cur != nullptr)
        {
            if(cur->data == target)
                cnt++;
            cur = cur->next;
        }
        return cnt;
    }
};

int main()
{
    int N;
    while (cin >> N && N != 0)
    {
        List L;
        for (int i=0;i<N;i++)
        {
            int d;
            cin>>d;
            L.push_back(d);
        }
        int target;
        cin>>target;
        int num = L.count(target);
        cout<<num<<"\n";
    }
    return 0;
}
