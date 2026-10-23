//
// Created by liuqi on 2026/9/29.
//
#include<iostream>
using namespace std;
#include <iostream>

// 1. 定义链表节点结构体
struct Node {
    int data;    // 数据域：存具体数值
    Node* next;  // 指针域：存下一个节点的地址
};

// 2. 创建新节点（在堆上开辟空间并初始化）
Node* CreateNode(int val) {
    Node* newNode = new Node;    // 堆上开辟完整节点空间
    newNode->data = val;         // 给堆里的data赋值
    newNode->next = nullptr;     // 指针域默认置空，避免野指针
    return newNode;              // 返回节点的首地址
}

// 3. 头插法：新节点插到链表最前面
void PushFront(Node*& head, int val) {
    Node* newNode = CreateNode(val);
    newNode->next = head;  // 新节点指向原来的第一个节点
    head = newNode;        // 更新头指针，指向新节点
}

// 4. 尾插法：新节点插到链表最后面
void PushBack(Node*& head, int val) {
    Node* newNode = CreateNode(val);
    // 空链表特殊处理：直接让头指针指向新节点
    if (head == nullptr) {
        head = newNode;
        return;
    }
    // 找到最后一个节点
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newNode;  // 尾节点的next指向新节点
}

// 5. 遍历打印整个链表
void PrintList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data << " -> ";
        cur = cur->next;
    }
    cout << "nullptr" << endl;
}

// 6. 查找值为val的节点
Node* FindNode(Node* head, int val) {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->data == val) {
            return cur;  // 找到返回节点地址
        }
        cur = cur->next;
    }
    return nullptr;  // 没找到返回空指针
}

// 7. 删除第一个值为val的节点
void RemoveNode(Node*& head, int val) {
    // 空链表直接返回
    if (head == nullptr) return;

    // 情况1：删除的是头节点
    if (head->data == val) {
        Node* temp = head;
        head = head->next;  // 头指针后移一位
        delete temp;        // 释放旧头节点的堆内存
        return;
    }

    // 情况2：删除中间/尾部节点，先找目标的前一个节点
    Node* pre = head;
    while (pre->next != nullptr) {
        if (pre->next->data == val) {
            Node* temp = pre->next;
            pre->next = temp->next;  // 跳过目标节点
            delete temp;             // 释放目标节点
            return;
        }
        pre = pre->next;
    }
}

// 8. 销毁整个链表，释放所有堆内存
void DestroyList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;  // 先移动头指针，再释放节点
        delete temp;
    }
    head = nullptr;  // 最后头指针置空，避免野指针
}

// 测试主函数
int main() {
    Node* head = nullptr;  // 初始化为空链表

    // 测试尾插
    PushBack(head, 10);
    PushBack(head, 20);
    PushBack(head, 30);
    cout << "尾插10、20、30后：";
    PrintList(head);

    // 测试头插
    PushFront(head, 5);
    PushFront(head, 1);
    cout << "头插5、1后：";
    PrintList(head);

    // 测试查找
    Node* p = FindNode(head, 20);
    if (p != nullptr) {
        cout << "找到值为20的节点" << endl;
    }

    // 测试删除中间节点
    RemoveNode(head, 10);
    cout << "删除值为10的节点后：";
    PrintList(head);

    // 测试删除头节点
    RemoveNode(head, 1);
    cout << "删除头节点1后：";
    PrintList(head);

    // 销毁链表（必须做，防止内存泄漏）
    DestroyList(head);
    cout << "销毁链表后：";
    PrintList(head);

    return 0;
}
