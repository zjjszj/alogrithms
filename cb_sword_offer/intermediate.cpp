#include<iostream>
#include<stack>

#include "intermediate.h"

using namespace std;

///����
//��ӽڵ㵽β�ڵ�
 void List::addToTail(int val){
     //�½�һ���ڵ�
    Node *node=new Node(val,nullptr);
    //����Ϊ��ֱ�Ӳ���
    if(this->head==nullptr){
        head=node;
    }else{
    //����Ϊ��
        Node *h=this->head;
        while(h->next!=nullptr){
            h=h->next;
        }
        h->next=node;
    }
}
//��������
void List::visitAll(){
    Node* n=head;
    if(n==nullptr){
        cout<<"������Ϊ������"<<endl;
    }else{
        cout<<"�����ֵΪ��";
        while(n!=nullptr){
            cout<<n->value<<" ";
            n=n->next;
        }
        cout<<endl;
    }
}
//��β��ͷ��ӡ����
/*����һ����ջ�ķ�ʽ
void List::printListReverse(){
    if(this->head==nullptr){
        return;
    }else{
        //����ջ
        stack<Node*> nodes;
        //��������
        while(head!=nullptr){
            nodes.push(this->head);
            this->head=this->head->next;
        }
        //���
        cout<<"��β��ͷԪ�طֱ��ǣ�";

        while(!nodes.empty()){
            Node *p=nodes.top();
            cout<<p->value<<" ";
            nodes.pop();
        }
    }
}
*/
//���������Եݹ�ķ�ʽ
void List::printListReverse(){
    if(head!=nullptr){
        Node* p=head;           //��û���βεĺ����ݹ�ʱ����Ҫ�Լ�����һ��������ÿ�εݹ�ʱ�ñ�������ֵ����ÿ�εݹ鶼������ͬ���ֵı�������������ͬ��
        //��ӡβ�ڵ�
        if(head->next!=nullptr){
            head=head->next;
            List::printListReverse();
        }
        cout<<p->value<<" ";
    }
}

///��




