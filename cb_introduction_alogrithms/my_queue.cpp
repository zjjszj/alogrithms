#include<iostream>

#include "my_queue.h"
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

}

template <typename T>
bool DoubleQueue<T>::queue_full(){

}

template<typename T>
bool DoubleQueue<T>::head_enqueue(T v){

}

template<typename T>
T DoubleQueue<T>::head_dequeue(){

}
template<typename T>
bool DoubleQueue<T>::tail_enqueue(T v){

}

template<typename T>
T DoubleQueue<T>::tail_dequeue(){

}

