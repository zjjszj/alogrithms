#ifndef MY_QUEUE_H_INCLUDED
#define MY_QUEUE_H_INCLUDED

///循环队列
template <typename T>
class My_Queue{
private:
    int length;
    int head;
    int tail;
    T* element;
public:
    My_Queue(){}
    My_Queue(int len):length(len),head(0),tail(0){
        element=new T[len];
    }
    ~My_Queue(){delete [] element;}
    //入队
    int enqueue(T x);
    //出队
    T dequeue();
};

///双端队列
template<typename T>
class DoubleQueue{
private:
    T *data;
    int head;
    int tail;
    int len1,len2;

public:
    DoubleQueue(){}
    DoubleQueue(int len1,int len2):len1(len1),len2(len2),head(len1+len2-1),tail(0){
        data=new T[len1+len2];
    }
    ~DoubleQueue(){delete [] data;}
    bool head_enqueue(T v);
    T head_dequeue();
    bool tail_enqueue(T v);
    T tail_dequeue();
    bool queue_empty();
    bool queue_full();
};







#endif // MY_QUEUE_H_INCLUDED
