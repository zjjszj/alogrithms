#include <iostream>
#include<array>
#include<vector>
#include<cmath>

#include "my_queue.h"
#include "my_queue.cpp"    ///也可以将模版函数的声明和定义都定义在头文件中

using namespace std;

void test();
///单例模式
class CSingleton
{
private:
	CSingleton()   //构造函数是私有的
	{
	}
	static CSingleton *m_pInstance;
public:
	static CSingleton * GetInstance()
	{
		if(m_pInstance == NULL)  //判断是否第一次调用
			m_pInstance = new CSingleton();
		return m_pInstance;
	}
};
CSingleton * CSingleton::m_pInstance=NULL;

CSingleton* p1 = CSingleton :: GetInstance();
///直接插入排序
void insertion(int *a,int);
///查找数组中重复元素1
void getRepeatNumber(int *a,int n);
///查找数组中重复元素2
/*
input:array,length of array,array of repeation element
output:return true if including repeation element.
*/
bool getRepeatNumber(int *,int n,std::vector<int> *repeat);
///一个最大子数组
//分治算法
array <int,3> find_max_cross_subarray(vector<int> v,int i,int j);
array<int,3> find_max_subarray(vector<int> v,int i,int j);
///矩阵乘法
/*
分治算法。
A、B均为n×n矩阵,n为2的幂。
*/
template<typename T>
struct Matrix {
  vector<vector<T>> Data;
  Matrix(size_t r, size_t c) {
    Data.resize(c, vector<T>(r, 0));
  }
  //求矩阵被分解部分的值
  //结果保存在C中
  void SetSubMatrix(const int r, const int c, const int rn, const int cn,
                    const Matrix<T>& A, const Matrix<T>& B) {
    for (int cl = c; cl < cn; ++cl)
      for (int rl = r; rl < rn; ++rl)
        Data[cl][rl] = A.Data[cl - c][rl - r] + B.Data[cl - c][rl - r];
  }
  //求以A[ar][ac]为左顶点长度为n的方阵乘以同样条件的方阵B的值
  static Matrix<T> SquareMultiplyRecursive(Matrix<T>& A, Matrix<T>& B,
                                           int ar, int ac, int br, int bc, int n) {
    Matrix<T> C(n, n);

    if (n == 1) {
      C.Data[0][0] = A.Data[ac][ar] * B.Data[bc][br];
    } else {
      //C11=A11*B11+A12*B12
      C.SetSubMatrix(0, 0, n / 2, n / 2,
        SquareMultiplyRecursive(A, B, ar, ac, br, bc, n / 2),       //方阵的长度为n/2，A11*B11
        SquareMultiplyRecursive(A, B, ar, ac + (n / 2), br + (n / 2), bc, n / 2));  //A12*B12
      //C12=A11*B12+A12*B21
      C.SetSubMatrix(0, n / 2, n / 2, n,
        SquareMultiplyRecursive(A, B, ar, ac, br, bc + (n / 2), n / 2),             //A11*B12
        SquareMultiplyRecursive(A, B, ar, ac + (n / 2), br + (n / 2), bc + (n / 2), n / 2));    //A12*B21

      C.SetSubMatrix(n / 2, 0, n, n / 2,
        SquareMultiplyRecursive(A, B, ar + (n / 2), ac, br, bc, n / 2),
        SquareMultiplyRecursive(A, B, ar + (n / 2), ac + (n / 2), br + (n / 2), bc, n / 2));

      C.SetSubMatrix(n / 2, n / 2, n, n,
        SquareMultiplyRecursive(A, B, ar + (n / 2), ac, br, bc + (n / 2), n / 2),
        SquareMultiplyRecursive(A, B, ar + (n / 2), ac + (n / 2), br + (n / 2), bc + (n / 2), n / 2));
    }
    return C;
  }

  void Print() {
    for (size_t c = 0; c < Data.size(); ++c) {
      for (size_t r = 0; r < Data[0].size(); ++r)
        std::cout << Data[c][r] << " ";
      std::cout << "\n";
    }
    std::cout << "\n";
  }
};

///堆排序
void max_heap_down(vector<int>& A,int i,int length);
void max_heap_up(vector<int>& A,int i);
void min_heap_down(vector<int>& A,int i,int length);
void min_heap_up(vector<int>& A,int i);
void build_heap(vector<int>& A);
void build_maxheap_up(vector<int>& A);
void build_maxheap_down(vector<int>& A);
void build_minheap_up(vector<int>& A);
void build_minheap_down(vector<int>& A);
void heap_sort(vector<int>& A);
///基于堆数据结构的优先队列
void extract_max(vector<int>& A);
int heap_max(vector<int>& A,int x);
void increase_key(vector<int>&A,int i,int k);
void heap_insert(vector<int>&A,int x);
///快速排序
vector<int>::iterator randomized_partition(vector<int>& A,vector<int>::iterator _begin,vector<int>::iterator _end);
void quickSort(vector<int>& A,vector<int>::iterator _begin,vector<int>::iterator _end);

///计数排序
vector<int> countingSort(vector<int>& A);







int main()
{
    ///直接插入排序
//    int L=8;
//    int a[]={5,3,8,2,9,0,2,1};
//    insertion(a,8);
//    for(int i=0;i<L;i++){s
//        cout<<a[i]<<" ";
//    }

    ///查找数组中重复元素1
//    int a[8]={1,2,3,4,3,3,2};
//    getRepeatNumber(a,8);

    ///查找数组中重复元素2
//    std::vector<int> *repeat=new vector<int>;
//    int a[8]={1,2,3,4,3,3,2,2};
//    bool isRepeat=getRepeatNumber(a,8,repeat);
//    if(isRepeat){
//        for(int n : (*repeat)){
//            cout<<"重复的元素是："<<n<<" ";
//        }
//    }

    ///一个最大子数组
//    vector<int> v={0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
//    array<int,3> result=find_max_subarray(v,0,v.size()-1);
//    cout<<"最大子数组的范围是："<<result[0]<<"到"<<result[1]<<";"<<"最大值为："<<result.at(2);

    ///矩阵乘法
    //分治算法
//  Matrix<int> A(2, 2);
//  Matrix<int> B(2, 2);
//
//  A.Data[0][0] = 2; A.Data[0][1] = 1;
//  A.Data[1][0] = 1; A.Data[1][1] = 2;
//
//  B.Data[0][0] = 2; B.Data[0][1] = 1;
//  B.Data[1][0] = 1; B.Data[1][1] = 2;
//
//  A.Print();
//  B.Print();
//
//  Matrix<int> C(Matrix<int>::SquareMultiplyRecursive(A, B, 0, 0, 0, 0, 2));
//  C.Print();

    /// 堆排序
    //1 维护堆的性质
//    vector<int> A={1,16,4,10,14,7,9,3,2,8,1};
//    max_heap_down(A,2,10);
//    for(auto e: A){
//        cout<<e<<endl;
//    }
//    vector<int> A={1,10,7,8,9,3};
//    max_heap_up(A,4,5);
//    for(auto e: A){
//        cout<<e<<endl;
//    }

//    vector<int> A={1,3,2,4,1,5,6,7,5,6};
//    min_heap_down(A,2);
//    for(auto e: A){
//        cout<<e<<endl;
//    }

    // 2 建大顶堆
//    vector<int> A={1,1,2,3,4,5};
//    build_maxheap_up(A);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

//    vector<int> A={1,1,2,3,4,5};
//    build_maxheap_down(A);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

    // 2.1 建小顶锥
//    vector<int> A={1,5,4,3,2,1};
//    build_minheap_down(A);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

//    vector<int> A={1,5,4,3,2,1};
//    build_minheap_up(A);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

//vector<int> A={1,16,4,10,14,7,9,3,2,8,1};
//heap_sort(A);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

///优先队列
//    vector<int> A={1,16,14,10,8,7,9,3,2,4,1};
//    extract_max(A);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

//    vector<int> A={1,16,14,13,10,8,10,5,7};
//    increase_key(A,4,17);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

//    vector<int> A={1,16,14,13,10,8,10,5,7};
//    heap_insert(A,11);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

//    vector<int> A={2,3,4,6,7,8,5};
//    quickSort(A,0,6);
//    for(auto e:A){
//        cout<<e<<endl;
//    }

//    vector<int> A={2,4,1,5,3,7,4};
//    vector<int> B=countingSort(A);
//    for(auto e:B){
//        cout<<e<<endl;
//    }

/// 循环队列
//My_Queue<int> q(5);
//int a=q.enqueue(1);
//int b=q.enqueue(2);
//cout<<a<<endl<<b<<endl;
//int d1=q.dequeue();
//cout<<d1<<endl;
//int d2=q.dequeue();
//cout<<d2<<endl;
//int d3=q.dequeue();
//cout<<d3<<endl;


///双链表
DoubleLinkQueue<int> dlq;
dlq.insert2Head(3);
dlq.insert2Tail(4);
dlq.insert2Tail(5);
//DLNode<int>* n=dlq._search(5);
bool b;
b=dlq._delete(3);
if(b){
    dlq.visitAll();
}else{
    cout<<"删除的元素不存在";
}


}

