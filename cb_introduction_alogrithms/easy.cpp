#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include <ctime>

using namespace std;
/*时间复杂度分析
1 比较排序（插入、归并、堆）最坏情况下时间复杂度的下界为O(nlgn),归并和堆排序是渐进最优的。

排序        平均时间复杂度     最坏时间复杂度       空间复杂度                  是否稳定         是否原址排序
插入排序    O(n^2)             O(n^2)                                              是                是
归并排序    O(nlgn)            O(nlgn)              O(n)                           是                否
堆排序      O(nlgn)            O(nlgn)                                             否                是
快速排序    O(nlgn)            O(n^2)                                              否                是
计数排序    O(n+k)             O(n+k)               O(k):k为元素中的最大值         是                是
基于计数排序的基数排序:d表示元素的位数，k表示每位的取值个数
            O(d(n+k))          O(d(n+k))            O(k)                           是                是
桶排序:假设桶内元素以链表形式存在，桶内排序使用插入排序
            O(n)               O(n)                 O(n)                           是                否



快速排序：时间复杂度依赖于划分，当平均分割成两个子数组时为最优，当分割成0和n-1个时为最坏情况时间复杂度为O(n^2)，当分割比例为常数
    时，时间复杂度总为O(n^2)，即使是99：1，只是隐含的系数比较大。
计数排序：假设元素在[0,k],当k=O(n)且主存空间比较大时，我们一般会使用计数排序。
桶排序：假设输入服从[0,1]上的均匀分布。


*/
void test(){
array<int,3> a;
a[0]=1;
a[1]=2;
a[2]=3;
cout<<a.at(0)<<a.at(1)<<a.at(2);
}

///直接插入排序
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
///找出数组中重复的数字1
/*
长度为n的数组，数组元素为0-n-1
example:长度为4[0，0，1，1] 输出为0或1
*/
#include<map>
void getRepeatNumber(int a[],int n){
    std::map<int,int> num_dict;
    for(int i=0;i<n;i++){
        num_dict[i]=0;
    }
    //遍历数组
    for(int i=0;i<n;i++){
        int j=0;
        while(j<a[i] && j<n){
            j++;
        }
        if(j==n){
            cout<<"数组取值不在范围内"<<endl;
            return;
        }else if(j==a[i]){
            num_dict[j]=num_dict[j]+1;
        }else{
            continue;
        }
    }
    //遍历map
    map<int,int>::iterator it;
    for(it=num_dict.begin();it!=num_dict.end();it++){
            if((*it).second>1){
                cout<<(*it).first<<" ";
            }
    }
}
///找出数组中重复数字2
bool getRepeatNumber(int a[],int n,std::vector<int> *repeat){
    bool flag=false;
    //遍历整个数组
    for(int i=0;i<n;i++){
        //为每个位置找到正确元素
        if(a[i]!=i){
            while(a[i]!=i && a[i]!=a[a[i]]){
                //交换元素值与元素值作为索引位置的值
                int temp=a[a[i]];
                a[a[i]]=a[i];
                a[i]=temp;
            }
            //重复元素
            if(a[i]==a[a[i]]){
                flag=true;
                repeat->push_back(a[i]);
            }
        }
    }
    return flag;
}

///一个最大子数组
/*    srand((unsigned)time(NULL));
分治算法
最大子数组在左半部分或右半部分或中间。若再中间部分，那么肯定包括值a[mid]和a[mid+1]
分解：两个部分数组
解决；分别解决两个部分数组
合并：合并两个解决的部分数组
*/
//求在中间的情况
array <int,3> find_max_cross_subarray(vector<int> v,int i,int j){
    int mid=(i+j)/2,max_left=v.at(mid),max_right=v.at(mid+1),sum_right=0,l=mid,r=mid+1,sum_left=0;
    //计算左边的最大子数组
    for(int index=mid;index>=i;index--){
        sum_left+=v.at(index);
        if(sum_left>max_left){
            max_left=sum_left;
            l=index;
        }
    }
    //计算右边的最大子数组
        for(int index=mid+1;index<=j;index++){
        sum_right+=v.at(index);
        if(sum_right>max_right){
            max_right=sum_right;
            r=index;
        }
    }
    //计算左右之和
    //cout<<max_left<<endl<<max_right<<endl;
    array<int,3> a={l,r,(max_left+max_right)};
    return a;
}
array<int,3> find_max_subarray(vector<int> v,int i,int j){
    array<int,3> r,r_left,r_right,r_cross;
    //一个元素
    if(i==j){
        r[0]=i;r[1]=i;r[2]=v.at(i);
        return r;
    }else{
    //计算左半部分
    int mid=(i+j)/2;
    r_left=find_max_subarray(v,i,mid);
    int max_left=r_left.at(2);
    //计算右半部分
    r_right=find_max_subarray(v,mid+1,j);
    int max_right=r_right.at(2);
    //计算中间部分
    r_cross=find_max_cross_subarray(v,i,j);
    int max_cross=r_cross.at(2);
    //返回最大值
    if(max_left>=max_right && max_left>=max_cross){
        return r_left;
    }else if(max_right>=max_left && max_right>=max_cross){
        return r_right;
    }else{
        return r_cross;
    }
    }
}

///快速排序
int randomized_partition(vector<int>& A,int l,int r){
    //随机选取主元素
    srand((unsigned)time(NULL));
    int i=rand()%(r-l+1)+l;
    cout<<"随机数i的值是："<<i<<endl;
    cout<<"主元素是："<<A.at(i)<<endl;
    swap(A.at(i),A.at(r));
    //划分
    int j=l;            //交换的位置
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

///计数排序
/*
假设元素在[0,k]
思想：计算小于等于数组中每个元素的个数。
B用于输出，C：临时数组，存放个数。
*/
vector<int> countingSort(vector<int>& A){
    vector<int> b,c;
    //找出最大值k
    int k=A.at(0);
    for(auto it=A.begin();it!=A.end();it++){
        if(k<*it){
            k=*it;
        }
    }
    //为c赋值
        // 1 每个元素的个数
    c.resize(k+1);
    for(int i=0;i<A.size();i++){
        c[A[i]]=c[A[i]]+1;
    }
        // 2 小于每个元素的个数
    for(int i=1;i<c.size();i++){
        c[i]=c[i]+c[i-1];
    }
    //为b赋值
    b.resize(A.size());
    for(int i=A.size()-1;i>=0;i--){        //从后向前遍历A，保证计数排序是稳定排序。
        b[c[A[i]]]=A[i];
        c[A[i]]--;
    }
    return b;
}

///基数排序
/*
思想：对每位元素（d位，每位包含k个取值），从最低位开始循环使用稳定排序算法直到最高位。稳定排序算法可以是计数排序。
*/
vector<int> radixSort(vector<int>& A,int d){
    vector<int> tmp;
    for(auto it=A.begin();it!=A.end();it++){

    }
}

/// 桶排序







