#include<iostream>
#include<vector>

using namespace std;
/*时间复杂度分析

建堆时间复杂度：O(n)
维护堆的性质时间复杂度：O(lgn)
堆排序的时间复杂度：O(nlgn)
所有优先队列操作的时间复杂度为O(lgn)
*/
///大顶锥
/*

建堆方式有两种：
1 从底层开始，对每一个节点调用维护顶锥性质的down函数。
2 从顶层开始，对每一个节点调用维护顶锥性质的up函数。
*/
/// 1 维护堆的性质
//假设以i为根节点的子结点符合大顶锥，使节点i符合大顶锥
void max_heap_down(vector<int>& A,int i,int length){
    //与最大子结点交换
    int left=2*i,right=2*i+1,largest=i;
    if(left<=length && A.at(left)>A.at(largest)){
        largest=left;
    }
    if(right<=length && A.at(right)>A.at(largest)){
        largest=right;
    }
    //递归该子结点
    if(largest!=i){
        swap(A.at(i),A.at(largest));
        max_heap_down(A,largest,length);
    }
}
//假设以i为根节点的子结点符合大顶锥，使节点i符合大顶锥
void max_heap_up(vector<int>& A,int i){

    int parent=i/2;
    if(parent && A.at(i)>A.at(parent)){
        swap(A.at(i),A.at(parent));
        max_heap_up(A,parent);
    }
}

///小顶锥
void min_heap_down(vector<int>& A,int i,int length){
    int left=i*2,right=2*i+1,smallest=i;
    if(left<=length && A.at(left)<A.at(i)){
        smallest=left;
    }
    if(right<=length && A.at(right)<A.at(left)){
        smallest=right;
    }
    if(smallest!=i){
        swap(A.at(i),A.at(smallest));
        min_heap_down(A,smallest,length);
    }
}

void min_heap_up(vector<int>& A,int i){
    int parent=i/2;
    if(parent && A.at(i)<A.at(parent)){
        swap(A.at(parent),A.at(i));
        min_heap_up(A,parent);
    }
}

/// 2 建堆
/*
只遍历非叶节点
*/
//建大顶锥
//从底部开始建堆
void build_maxheap_down(vector<int>& A){
    for(int i=(A.size()-1)/2;i>=1;i--){
        max_heap_down(A,i,A.size()-1);
    }
}
//从顶部开始建堆
void build_maxheap_up(vector<int>& A){
    for(int i=2;i<A.size();i++){
        max_heap_up(A,i);
    }
}
//建小顶锥
void build_minheap_down(vector<int>& A){
    for(int i=(A.size()-1)/2;i>=1;i--){
        min_heap_down(A,i,A.size()-1);
    }
}

void build_minheap_up(vector<int>& A){
    for(int i=2;i<A.size();i++){
        min_heap_up(A,i);
    }
}

///堆排序
void heap_sort(vector<int>& A){
    //建堆
    build_maxheap_down(A);
    for(int i=A.size()-1;i>1;i--){
        //交换位置
        swap(A.at(1),A.at(i));
        //保持堆的性质
        max_heap_down(A,1,i-1);
    }
}
///基于堆数据结构实现的优先队列
/*
优先队列：一种用来维护由一组元素构成的集合S的数据结构，每一个元素称为关键字，关键字和应用程序对象相关联。
两种形式：最大优先队列和最小优先队列。只实现最大优先队列。
应用：作业调度。
最大优先队列支持的算法：insert(S,x)     max(S)       extract_max(S)      increase_key(S,i,k)
*/
int heap_max(vector<int>& A,int x){
    return A.at(1);
}
/*
交换A[1]与A[A.size()-1]--->维护堆的性质-->删除最后一个元素
参数：A：大顶锥
*/
void extract_max(vector<int>& A){
    //交换
    swap(A[1],A[A.size()-1]);
    //维护
    max_heap_down(A,1,A.size()-2);
    //删除
    A.erase(A.end()-1);
}
/*
将下标为i的元素值增加到k
*/
void increase_key(vector<int>&A,int i,int k){
    //增加
    A.at(i)=k;
    //维护堆的性质
    max_heap_up(A,i);
}

void heap_insert(vector<int>&A,int x){
    A.push_back(x);
    max_heap_up(A,A.size()-1);
}




