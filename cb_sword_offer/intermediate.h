#ifndef INTERMEDIATE_H_INCLUDED
#define INTERMEDIATE_H_INCLUDED

#include <iostream>

/// 1 链表
// 1 插入
//节点
class Node{
public:
    int value;
    Node* next;
    //构造函数
    Node(int value,Node* next){
        this->value=value;
        this->next=next;
    }
};
//链表
class List{
private:
    Node *head;
public:
    List(){head=nullptr;};
    ~List(){delete head;};
    //添加节点到尾节点
    void addToTail(int val);
    //遍历链表
    void visitAll();
    //从尾到头打印链表
    void printListReverse();


};




#endif // INTERMEDIATE_H_INCLUDED

