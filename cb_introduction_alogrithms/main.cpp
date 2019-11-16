#include <iostream>
#include<array>
#include<vector>
#include<cmath>

#include "my_queue.h"
#include "my_queue.cpp"    ///Ҳ���Խ�ģ�溯���������Ͷ��嶼������ͷ�ļ���

using namespace std;

void test();
///����ģʽ
class CSingleton
{
private:
	CSingleton()   //���캯����˽�е�
	{
	}
	static CSingleton *m_pInstance;
public:
	static CSingleton * GetInstance()
	{
		if(m_pInstance == NULL)  //�ж��Ƿ��һ�ε���
			m_pInstance = new CSingleton();
		return m_pInstance;
	}
};
CSingleton * CSingleton::m_pInstance=NULL;

CSingleton* p1 = CSingleton :: GetInstance();
///ֱ�Ӳ�������
void insertion(int *a,int);
///�����������ظ�Ԫ��1
void getRepeatNumber(int *a,int n);
///�����������ظ�Ԫ��2
/*
input:array,length of array,array of repeation element
output:return true if including repeation element.
*/
bool getRepeatNumber(int *,int n,std::vector<int> *repeat);
///һ�����������
//�����㷨
array <int,3> find_max_cross_subarray(vector<int> v,int i,int j);
array<int,3> find_max_subarray(vector<int> v,int i,int j);
///����˷�
/*
�����㷨��
A��B��Ϊn��n����,nΪ2���ݡ�
*/
template<typename T>
struct Matrix {
  vector<vector<T>> Data;
  Matrix(size_t r, size_t c) {
    Data.resize(c, vector<T>(r, 0));
  }
  //����󱻷ֽⲿ�ֵ�ֵ
  //���������C��
  void SetSubMatrix(const int r, const int c, const int rn, const int cn,
                    const Matrix<T>& A, const Matrix<T>& B) {
    for (int cl = c; cl < cn; ++cl)
      for (int rl = r; rl < rn; ++rl)
        Data[cl][rl] = A.Data[cl - c][rl - r] + B.Data[cl - c][rl - r];
  }
  //����A[ar][ac]Ϊ�󶥵㳤��Ϊn�ķ������ͬ�������ķ���B��ֵ
  static Matrix<T> SquareMultiplyRecursive(Matrix<T>& A, Matrix<T>& B,
                                           int ar, int ac, int br, int bc, int n) {
    Matrix<T> C(n, n);

    if (n == 1) {
      C.Data[0][0] = A.Data[ac][ar] * B.Data[bc][br];
    } else {
      //C11=A11*B11+A12*B12
      C.SetSubMatrix(0, 0, n / 2, n / 2,
        SquareMultiplyRecursive(A, B, ar, ac, br, bc, n / 2),       //����ĳ���Ϊn/2��A11*B11
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

///������
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
///���ڶ����ݽṹ�����ȶ���
void extract_max(vector<int>& A);
int heap_max(vector<int>& A,int x);
void increase_key(vector<int>&A,int i,int k);
void heap_insert(vector<int>&A,int x);
///��������
vector<int>::iterator randomized_partition(vector<int>& A,vector<int>::iterator _begin,vector<int>::iterator _end);
void quickSort(vector<int>& A,vector<int>::iterator _begin,vector<int>::iterator _end);

///��������
vector<int> countingSort(vector<int>& A);







int main()
{
    ///ֱ�Ӳ�������
//    int L=8;
//    int a[]={5,3,8,2,9,0,2,1};
//    insertion(a,8);
//    for(int i=0;i<L;i++){s
//        cout<<a[i]<<" ";
//    }

    ///�����������ظ�Ԫ��1
//    int a[8]={1,2,3,4,3,3,2};
//    getRepeatNumber(a,8);

    ///�����������ظ�Ԫ��2
//    std::vector<int> *repeat=new vector<int>;
//    int a[8]={1,2,3,4,3,3,2,2};
//    bool isRepeat=getRepeatNumber(a,8,repeat);
//    if(isRepeat){
//        for(int n : (*repeat)){
//            cout<<"�ظ���Ԫ���ǣ�"<<n<<" ";
//        }
//    }

    ///һ�����������
//    vector<int> v={0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
//    array<int,3> result=find_max_subarray(v,0,v.size()-1);
//    cout<<"���������ķ�Χ�ǣ�"<<result[0]<<"��"<<result[1]<<";"<<"���ֵΪ��"<<result.at(2);

    ///����˷�
    //�����㷨
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

    /// ������
    //1 ά���ѵ�����
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

    // 2 ���󶥶�
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

    // 2.1 ��С��׶
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

///���ȶ���
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

/// ѭ������
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


///˫����
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
    cout<<"ɾ����Ԫ�ز�����";
}


}

