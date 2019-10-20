#include<iostream>
#include<vector>

using namespace std;
/*ʱ�临�Ӷȷ���

����ʱ�临�Ӷȣ�O(n)
ά���ѵ�����ʱ�临�Ӷȣ�O(lgn)
�������ʱ�临�Ӷȣ�O(nlgn)
�������ȶ��в�����ʱ�临�Ӷ�ΪO(lgn)
*/
///��׶
/*

���ѷ�ʽ�����֣�
1 �ӵײ㿪ʼ����ÿһ���ڵ����ά����׶���ʵ�down������
2 �Ӷ��㿪ʼ����ÿһ���ڵ����ά����׶���ʵ�up������
*/
/// 1 ά���ѵ�����
//������iΪ���ڵ���ӽ����ϴ�׶��ʹ�ڵ�i���ϴ�׶
void max_heap_down(vector<int>& A,int i,int length){
    //������ӽ�㽻��
    int left=2*i,right=2*i+1,largest=i;
    if(left<=length && A.at(left)>A.at(largest)){
        largest=left;
    }
    if(right<=length && A.at(right)>A.at(largest)){
        largest=right;
    }
    //�ݹ���ӽ��
    if(largest!=i){
        swap(A.at(i),A.at(largest));
        max_heap_down(A,largest,length);
    }
}
//������iΪ���ڵ���ӽ����ϴ�׶��ʹ�ڵ�i���ϴ�׶
void max_heap_up(vector<int>& A,int i){

    int parent=i/2;
    if(parent && A.at(i)>A.at(parent)){
        swap(A.at(i),A.at(parent));
        max_heap_up(A,parent);
    }
}

///С��׶
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

/// 2 ����
/*
ֻ������Ҷ�ڵ�
*/
//����׶
//�ӵײ���ʼ����
void build_maxheap_down(vector<int>& A){
    for(int i=(A.size()-1)/2;i>=1;i--){
        max_heap_down(A,i,A.size()-1);
    }
}
//�Ӷ�����ʼ����
void build_maxheap_up(vector<int>& A){
    for(int i=2;i<A.size();i++){
        max_heap_up(A,i);
    }
}
//��С��׶
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

///������
void heap_sort(vector<int>& A){
    //����
    build_maxheap_down(A);
    for(int i=A.size()-1;i>1;i--){
        //����λ��
        swap(A.at(1),A.at(i));
        //���ֶѵ�����
        max_heap_down(A,1,i-1);
    }
}
///���ڶ����ݽṹʵ�ֵ����ȶ���
/*
���ȶ��У�һ������ά����һ��Ԫ�ع��ɵļ���S�����ݽṹ��ÿһ��Ԫ�س�Ϊ�ؼ��֣��ؼ��ֺ�Ӧ�ó�������������
������ʽ��������ȶ��к���С���ȶ��С�ֻʵ��������ȶ��С�
Ӧ�ã���ҵ���ȡ�
������ȶ���֧�ֵ��㷨��insert(S,x)     max(S)       extract_max(S)      increase_key(S,i,k)
*/
int heap_max(vector<int>& A,int x){
    return A.at(1);
}
/*
����A[1]��A[A.size()-1]--->ά���ѵ�����-->ɾ�����һ��Ԫ��
������A����׶
*/
void extract_max(vector<int>& A){
    //����
    swap(A[1],A[A.size()-1]);
    //ά��
    max_heap_down(A,1,A.size()-2);
    //ɾ��
    A.erase(A.end()-1);
}
/*
���±�Ϊi��Ԫ��ֵ���ӵ�k
*/
void increase_key(vector<int>&A,int i,int k){
    //����
    A.at(i)=k;
    //ά���ѵ�����
    max_heap_up(A,i);
}

void heap_insert(vector<int>&A,int x){
    A.push_back(x);
    max_heap_up(A,A.size()-1);
}




