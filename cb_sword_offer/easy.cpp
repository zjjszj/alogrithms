#include <iostream>
#include<vector>
#include<string>


using namespace std;


///可改进
/// 1 查找数组中任意一个重复元素
//类似二分法：从数组元素取值范围的中间分成两部分，计算每部分元素的个数，如果元素个数大于区间长度，则在分该部分数据。最后查找
    //某个数字是否重复。
//example：length:n+1,element:1-n. m:middle of 1-n, 数组分为1-m和m+1-n。检查数组中值为1-m的个数，若大于m则包含重复元素，
    //在1-m中继续划分
//O(n)=O(n*logn):   n:每次查找需要执行的次数   logn:需要查找的次数。
int getDuplication(int *numbers,int len,int left,int right){
    if(left>right){
        //返回重复元素
        return right;

    }
    if(left==right){
        //返回重复元素
        return left;
    }
    //计算中值
    int mid=(left+right)/2;
    //区间内元素个数
    int ele_count=0;
    //查找左部分
    for(int i=0;i<len;i++){
        if(numbers[i]<=mid && numbers[i]>=left){
            ele_count++;
        }
    }
    if(ele_count>(mid-left+1)){
       return  getDuplication(numbers,len,left,mid);
    }
    //查找右部分
    ele_count=0;
    for(int i=0;i<len;i++){
        if(numbers[i]<=right && numbers[i]>=(mid+1)){
            ele_count++;
        }
    }
    if(ele_count>(right-mid)){
        return getDuplication(numbers,len,mid+1,right);
    }
}
/// 2 替换字符串中的字符：用%20替换字符串中的空格
//方法一
//从后向前查找空格在移动字符并替换，时间复杂度为O(n)，从前向后的话时间复杂度为O(n^2)
string replace_string(string str){
    //计算空格总数
    int i=0,sum=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            sum++;
        }
        i++;
    }
    int c=0;                      //空格的个数
    string tmp=string(2*sum,' ');      //为str增加空间使用的空字符串
    str+=tmp;
    for(string::iterator i=str.end();i>=str.begin();i--){
        if(*i==' '){
            c++;
            //移动字符：j为字符串的尾指针
            string::iterator j=(str.end())+2*(c-1);
            while(j!=i){
                *(j+2)=*j;
                j--;
            }
            //赋值%20
            *i='%';*(i+1)='2';*(i+2)='0';
        }
    }
    return str;
}




