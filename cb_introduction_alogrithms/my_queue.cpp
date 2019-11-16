#include<iostream>

#include "my_queue.h"

using namespace std;
///普通队列：
//1 head指向最先出的元素，tail指向最后一根元素的下一个位置。
///双端队列：
//1 两个指针：head和tail。head指向新插入的元素，tail指向新插入元素的下一个位置。
//2 左右两边先入后出。

///循环队列
//入队
template <typename T>
int My_Queue<T>::enqueue(T x){
   if(this->length==0){  //队列的容量
        return -1;
    }
    //判断是否上溢
    if((this->tail+1)%this->length==this->head){
        return -1;
    }else{
        int index=this->tail%this->length;
        this->element[index]=x;
        this->tail=(this->tail+1)%this->length;
        return index;
    }
}
//出队
template <typename T>
T My_Queue<T>::dequeue(){
   if(this->length==0){
        return -1;
    }
    //判断是否下溢
    if(this->tail!=this->head){
        T tmp=this->element[this->head];
        this->head=(this->head+1)%this->length;
        return tmp;
    }
    return -1;
}
///双端队列
template <typename T>
bool DoubleQueue<T>::queue_empty(){
    return true;
}

template <typename T>
bool DoubleQueue<T>::queue_full(){
    return true;

}

template<typename T>
bool DoubleQueue<T>::head_enqueue(T v){
    return true;
}

template<typename T>
T DoubleQueue<T>::head_dequeue(){
    return true;
}
template<typename T>
bool DoubleQueue<T>::tail_enqueue(T v){
    return true;
}

template<typename T>
T DoubleQueue<T>::tail_dequeue(){

}

///双向链表
//遍历链表
template<typename T>
void DoubleLinkQueue<T>::visitAll() const{
    DLNode<T>* d;
    d=this->head;
    while(d){
        cout<<d->data<<endl;
        d=d->next;
    }
}
//从头结点插入结点
template<typename T>
void DoubleLinkQueue<T>::insert2Head(const T& value){
    DLNode<T>* newnode=new DLNode<T>;
    newnode->data=value;
    newnode->prior=nullptr;
    newnode->next=this->head;
    this->head=newnode;
    if(!this->tail){
        this->tail=newnode;
    }
}
//从尾结点插入新结点
template<typename T>
void DoubleLinkQueue<T>::insert2Tail(const T& value){
    DLNode<T> *nn=new DLNode<T>;
    nn->data=value;
    nn->next=nullptr;
    nn->prior=this->tail;
    if(this->tail){
        this->tail->next=nn;
    }
    this->tail=nn;
}
//查找指定元素
template<typename T>
DLNode<T> * DoubleLinkQueue<T>::_search(const T& value) const{
    DLNode<T> * h=this->head;
    while(h){
        if(h->data==value){
            return h;
        }
        h=h->next;
    }
    return nullptr;
}
//删除指定元素
template<typename T>
bool DoubleLinkQueue<T>::_delete(const T& value){
    DLNode<T> *n=this->_search(value);
    if(n==nullptr){
        return false;
    }
    if(n->next!=nullptr){
        n->next->prior=n->prior;
    }
    if(n->prior!=nullptr){
        n->prior->next=n->next;
    }else{
        this->head=n->next;
    }
    delete(n);
    return true;
}






