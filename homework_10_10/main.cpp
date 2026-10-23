#include <iostream>


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

                //释放每一个节点

                for(Node *t = head; t != nullptr;){

                        t = t->next;

                        delete head;

                        head = t;

                }

        }

        //链表尾添加一个元素

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


        void pop_back()
        {
                if (head == nullptr)
                {
                        return;
                }
                if (head->next == nullptr)
                {
                        delete head;
                        head = nullptr;
                        size--;
                        return;
                }
                Node *t = head;
                while (t->next->next != nullptr)
                {
                        t = t->next;
                }
                delete t->next;
                t->next = nullptr;
                size--;
        }



        //链表头插入元素

        void push_front(int d)
        {
                Node *t = new Node(d);
                t->next = head;
                head = t;
                size++;
        }



        //链表头删除一个元素

        void pop_front()
        {
                if (head == nullptr)
                {
                        return;
                }
                Node *t = head;
                head = head->next;
                delete t;
                size--;
        }





        void printAll(){

                for(Node *t = head; t != nullptr; t = t->next)

                        std::cout << t->data << " ";

                std::cout << "\n";

        }

};



int main(int argc, const char * argv[]) {

        List a;

        a.push_front(10);

        a.printAll();

        a.pop_back();

        a.printAll();

        a.pop_back();

        for(int i = 0; i < 5; ++i)

                a.push_back(i);

        a.printAll();

        while(a.get_size() != 0)

                a.pop_front();

        a.printAll();



        return 0;

}