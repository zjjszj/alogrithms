#ifndef INTERMEDIATE_H_INCLUDED
#define INTERMEDIATE_H_INCLUDED

#include <iostream>

/// 1 ����
// 1 ����
//�ڵ�
class Node{
public:
    int value;
    Node* next;
    //���캯��
    Node(int value,Node* next){
        this->value=value;
        this->next=next;
    }
};
//����
class List{
private:
    Node *head;
public:
    List(){head=nullptr;};
    ~List(){delete head;};
    //��ӽڵ㵽β�ڵ�
    void addToTail(int val);
    //��������
    void visitAll();
    //��β��ͷ��ӡ����
    void printListReverse();


};




#endif // INTERMEDIATE_H_INCLUDED

