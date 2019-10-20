#include<vector>
#include<iostream>

using namespace std;

class MyQueue {
public:
    vector<int> first;
    vector<int> second;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        //第二个弹到第一个
        for(int i=0;i<second.size();i++){
            first.push_back(second.back());
            second.pop_back();
        }
        //x放到第二个
        second.push_back(x);
        //第一个弹回第二个
        for(int i=0;i<first.size();i++){
            second.push_back(first.back());
            first.pop_back();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //弹出第二个
        int tmp= second.back();
        second.pop_back();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        //返回第二个
        return second.back();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        //第二个是否为空
        return second.empty();

    }
};


vector<int> first,second;



int pop() {
    //弹出第二个
    int tmp= second.back();
    second.pop_back();
    return tmp;
}

void push(int x) {

    cout<<"==1====="<<endl;
    for(int i=0;i<first.size();i++){
        cout<<first.at(i)<<endl;
    }
    cout<<"===1======"<<endl;
    for(int i=0;i<second.size();i++){
        cout<<second.at(i)<<endl;
    }
    cout<<"====2====="<<endl;
    //第二个弹到第一个
    for(int i=0;i<second.size();i++){
        first.push_back(second.back());
        second.pop_back();
    }


    //x放到第二个
    second.push_back(x);


    //第一个弹回第二个
    for(int i=0;i<first.size();i++){
        second.push_back(first.back());
        first.pop_back();
    }
}


int main(){
//    push(1);
//    push(2);
//    push(3);
    //push(3);
    //int p1=pop();
    //int p2=pop();
    //int p3=pop();
    //cout<<p1<<p2;
    second.push_back(1);
    second.push_back(2);
    second.push_back(3);
    while(second.size()!=0){
         cout<<"second.size()"<<second.size()<<endl;

        second.pop_back();
    }
    for(int i=0;i<second.size();i++){
        cout<<"second.size()"<<second.size()<<endl;

        second.pop_back();
    }
    for(int i=0;i<first.size();i++){
        cout<<first.at(i)<<endl;
    }

    return 1;
}

