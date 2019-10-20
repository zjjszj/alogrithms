#include<iostream>
#include<stack>

#include "intermediate.h"

using namespace std;

///链表
//添加节点到尾节点
 void List::addToTail(int val){
     //新建一个节点
    Node *node=new Node(val,nullptr);
    //链表为空直接插入
    if(this->head==nullptr){
        head=node;
    }else{
    //链表不为空
        Node *h=this->head;
        while(h->next!=nullptr){
            h=h->next;
        }
        h->next=node;
    }
}
//遍历链表
void List::visitAll(){
    Node* n=head;
    if(n==nullptr){
        cout<<"该链表为空链表"<<endl;
    }else{
        cout<<"链表的值为：";
        while(n!=nullptr){
            cout<<n->value<<" ";
            n=n->next;
        }
        cout<<endl;
    }
}
//从尾到头打印链表
/*方法一：以栈的方式
void List::printListReverse(){
    if(this->head==nullptr){
        return;
    }else{
        //定义栈
        stack<Node*> nodes;
        //遍历链表
        while(head!=nullptr){
            nodes.push(this->head);
            this->head=this->head->next;
        }
        //输出
        cout<<"从尾到头元素分别是：";

        while(!nodes.empty()){
            Node *p=nodes.top();
            cout<<p->value<<" ";
            nodes.pop();
        }
    }
}
*/
//方法二：以递归的方式
void List::printListReverse(){
    if(head!=nullptr){
        Node* p=head;           //当没有形参的函数递归时，需要自己定义一个变量，每次递归时该变量保存值。（每次递归都会生成同名字的变量但是作用域不同）
        //打印尾节点
        if(head->next!=nullptr){
            head=head->next;
            List::printListReverse();
        }
        cout<<p->value<<" ";
    }
}

///树




