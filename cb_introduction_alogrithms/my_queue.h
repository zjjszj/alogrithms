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

///链队

// 1 双向链表
template<typename T>
class DLNode{
public:
    T data;
    DLNode<T>* prior;
    DLNode<T>* next;
};

template<typename T>
class DoubleLinkQueue{
private:
    DLNode<T>* head;
    DLNode<T>* tail;
public:
    DoubleLinkQueue(){head=tail=nullptr;};
    void insert2Head(const T& value);
    void insert2Tail(const T& value);
    bool _delete(const T& value);
    DLNode<T> * _search(const T& value) const;  //不会改变类的数据成员，该函数是只读函数
    void visitAll() const;
};





#endif // MY_QUEUE_H_INCLUDED
