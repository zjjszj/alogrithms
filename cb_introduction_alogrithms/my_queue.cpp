#include<iostream>

#include "my_queue.h"
///��ͨ���У�
//1 headָ�����ȳ���Ԫ�أ�tailָ�����һ��Ԫ�ص���һ��λ�á�
///˫�˶��У�
//1 ����ָ�룺head��tail��headָ���²����Ԫ�أ�tailָ���²���Ԫ�ص���һ��λ�á�
//2 ����������������

///ѭ������
//���
template <typename T>
int My_Queue<T>::enqueue(T x){
   if(this->length==0){  //���е�����
        return -1;
    }
    //�ж��Ƿ�����
    if((this->tail+1)%this->length==this->head){
        return -1;
    }else{
        int index=this->tail%this->length;
        this->element[index]=x;
        this->tail=(this->tail+1)%this->length;
        return index;
    }
}
//����
template <typename T>
T My_Queue<T>::dequeue(){
   if(this->length==0){
        return -1;
    }
    //�ж��Ƿ�����
    if(this->tail!=this->head){
        T tmp=this->element[this->head];
        this->head=(this->head+1)%this->length;
        return tmp;
    }
    return -1;
}
///˫�˶���
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

