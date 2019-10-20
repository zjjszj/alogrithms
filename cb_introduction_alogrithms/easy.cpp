#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include <ctime>

using namespace std;
/*ʱ�临�Ӷȷ���
1 �Ƚ����򣨲��롢�鲢���ѣ�������ʱ�临�Ӷȵ��½�ΪO(nlgn),�鲢�Ͷ������ǽ������ŵġ�

����        ƽ��ʱ�临�Ӷ�     �ʱ�临�Ӷ�       �ռ临�Ӷ�                  �Ƿ��ȶ�         �Ƿ�ԭַ����
��������    O(n^2)             O(n^2)                                              ��                ��
�鲢����    O(nlgn)            O(nlgn)              O(n)                           ��                ��
������      O(nlgn)            O(nlgn)                                             ��                ��
��������    O(nlgn)            O(n^2)                                              ��                ��
��������    O(n+k)             O(n+k)               O(k):kΪԪ���е����ֵ         ��                ��
���ڼ�������Ļ�������:d��ʾԪ�ص�λ����k��ʾÿλ��ȡֵ����
            O(d(n+k))          O(d(n+k))            O(k)                           ��                ��
Ͱ����:����Ͱ��Ԫ����������ʽ���ڣ�Ͱ������ʹ�ò�������
            O(n)               O(n)                 O(n)                           ��                ��



��������ʱ�临�Ӷ������ڻ��֣���ƽ���ָ������������ʱΪ���ţ����ָ��0��n-1��ʱΪ����ʱ�临�Ӷ�ΪO(n^2)�����ָ����Ϊ����
    ʱ��ʱ�临�Ӷ���ΪO(n^2)����ʹ��99��1��ֻ��������ϵ���Ƚϴ�
�������򣺼���Ԫ����[0,k],��k=O(n)������ռ�Ƚϴ�ʱ������һ���ʹ�ü�������
Ͱ���򣺼����������[0,1]�ϵľ��ȷֲ���


*/
void test(){
array<int,3> a;
a[0]=1;
a[1]=2;
a[2]=3;
cout<<a.at(0)<<a.at(1)<<a.at(2);
}

///ֱ�Ӳ�������
void insertion(int a[],int L){
    int key=0,i=0;
    for(int j=1;j<L;j++){
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]<key){
            a[i+1]=a[i];

            i=i-1;
        }
        a[i+1]=key;
    }
}
///�ҳ��������ظ�������1
/*
����Ϊn�����飬����Ԫ��Ϊ0-n-1
example:����Ϊ4[0��0��1��1] ���Ϊ0��1
*/
#include<map>
void getRepeatNumber(int a[],int n){
    std::map<int,int> num_dict;
    for(int i=0;i<n;i++){
        num_dict[i]=0;
    }
    //��������
    for(int i=0;i<n;i++){
        int j=0;
        while(j<a[i] && j<n){
            j++;
        }
        if(j==n){
            cout<<"����ȡֵ���ڷ�Χ��"<<endl;
            return;
        }else if(j==a[i]){
            num_dict[j]=num_dict[j]+1;
        }else{
            continue;
        }
    }
    //����map
    map<int,int>::iterator it;
    for(it=num_dict.begin();it!=num_dict.end();it++){
            if((*it).second>1){
                cout<<(*it).first<<" ";
            }
    }
}
///�ҳ��������ظ�����2
bool getRepeatNumber(int a[],int n,std::vector<int> *repeat){
    bool flag=false;
    //������������
    for(int i=0;i<n;i++){
        //Ϊÿ��λ���ҵ���ȷԪ��
        if(a[i]!=i){
            while(a[i]!=i && a[i]!=a[a[i]]){
                //����Ԫ��ֵ��Ԫ��ֵ��Ϊ����λ�õ�ֵ
                int temp=a[a[i]];
                a[a[i]]=a[i];
                a[i]=temp;
            }
            //�ظ�Ԫ��
            if(a[i]==a[a[i]]){
                flag=true;
                repeat->push_back(a[i]);
            }
        }
    }
    return flag;
}

///һ�����������
/*    srand((unsigned)time(NULL));
�����㷨
�������������벿�ֻ��Ұ벿�ֻ��м䡣�����м䲿�֣���ô�϶�����ֵa[mid]��a[mid+1]
�ֽ⣺������������
������ֱ���������������
�ϲ����ϲ���������Ĳ�������
*/
//�����м�����
array <int,3> find_max_cross_subarray(vector<int> v,int i,int j){
    int mid=(i+j)/2,max_left=v.at(mid),max_right=v.at(mid+1),sum_right=0,l=mid,r=mid+1,sum_left=0;
    //������ߵ����������
    for(int index=mid;index>=i;index--){
        sum_left+=v.at(index);
        if(sum_left>max_left){
            max_left=sum_left;
            l=index;
        }
    }
    //�����ұߵ����������
        for(int index=mid+1;index<=j;index++){
        sum_right+=v.at(index);
        if(sum_right>max_right){
            max_right=sum_right;
            r=index;
        }
    }
    //��������֮��
    //cout<<max_left<<endl<<max_right<<endl;
    array<int,3> a={l,r,(max_left+max_right)};
    return a;
}
array<int,3> find_max_subarray(vector<int> v,int i,int j){
    array<int,3> r,r_left,r_right,r_cross;
    //һ��Ԫ��
    if(i==j){
        r[0]=i;r[1]=i;r[2]=v.at(i);
        return r;
    }else{
    //������벿��
    int mid=(i+j)/2;
    r_left=find_max_subarray(v,i,mid);
    int max_left=r_left.at(2);
    //�����Ұ벿��
    r_right=find_max_subarray(v,mid+1,j);
    int max_right=r_right.at(2);
    //�����м䲿��
    r_cross=find_max_cross_subarray(v,i,j);
    int max_cross=r_cross.at(2);
    //�������ֵ
    if(max_left>=max_right && max_left>=max_cross){
        return r_left;
    }else if(max_right>=max_left && max_right>=max_cross){
        return r_right;
    }else{
        return r_cross;
    }
    }
}

///��������
int randomized_partition(vector<int>& A,int l,int r){
    //���ѡȡ��Ԫ��
    srand((unsigned)time(NULL));
    int i=rand()%(r-l+1)+l;
    cout<<"�����i��ֵ�ǣ�"<<i<<endl;
    cout<<"��Ԫ���ǣ�"<<A.at(i)<<endl;
    swap(A.at(i),A.at(r));
    //����
    int j=l;            //������λ��
    for(int i=l;i<=r-1;i++){
        if(A.at(i)<=A.at(r)){
            swap(A.at(j),A.at(i));
            j++;
        }
    }
    swap(A.at(j),A.at(r));
    return j;
}
void quickSort(vector<int>& A,int l,int r){
    if(l<r){
        int e=randomized_partition(A,l,r);
        quickSort(A,l,e-1);
        quickSort(A,e+1,r);
    }
}

///��������
/*
����Ԫ����[0,k]
˼�룺����С�ڵ���������ÿ��Ԫ�صĸ�����
B���������C����ʱ���飬��Ÿ�����
*/
vector<int> countingSort(vector<int>& A){
    vector<int> b,c;
    //�ҳ����ֵk
    int k=A.at(0);
    for(auto it=A.begin();it!=A.end();it++){
        if(k<*it){
            k=*it;
        }
    }
    //Ϊc��ֵ
        // 1 ÿ��Ԫ�صĸ���
    c.resize(k+1);
    for(int i=0;i<A.size();i++){
        c[A[i]]=c[A[i]]+1;
    }
        // 2 С��ÿ��Ԫ�صĸ���
    for(int i=1;i<c.size();i++){
        c[i]=c[i]+c[i-1];
    }
    //Ϊb��ֵ
    b.resize(A.size());
    for(int i=A.size()-1;i>=0;i--){        //�Ӻ���ǰ����A����֤�����������ȶ�����
        b[c[A[i]]]=A[i];
        c[A[i]]--;
    }
    return b;
}

///��������
/*
˼�룺��ÿλԪ�أ�dλ��ÿλ����k��ȡֵ���������λ��ʼѭ��ʹ���ȶ������㷨ֱ�����λ���ȶ������㷨�����Ǽ�������
*/
vector<int> radixSort(vector<int>& A,int d){
    vector<int> tmp;
    for(auto it=A.begin();it!=A.end();it++){

    }
}

/// Ͱ����







