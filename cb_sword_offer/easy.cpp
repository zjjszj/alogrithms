#include <iostream>
#include<vector>
#include<string>


using namespace std;


///�ɸĽ�
/// 1 ��������������һ���ظ�Ԫ��
//���ƶ��ַ���������Ԫ��ȡֵ��Χ���м�ֳ������֣�����ÿ����Ԫ�صĸ��������Ԫ�ظ����������䳤�ȣ����ڷָò������ݡ�������
    //ĳ�������Ƿ��ظ���
//example��length:n+1,element:1-n. m:middle of 1-n, �����Ϊ1-m��m+1-n�����������ֵΪ1-m�ĸ�����������m������ظ�Ԫ�أ�
    //��1-m�м�������
//O(n)=O(n*logn):   n:ÿ�β�����Ҫִ�еĴ���   logn:��Ҫ���ҵĴ�����
int getDuplication(int *numbers,int len,int left,int right){
    if(left>right){
        //�����ظ�Ԫ��
        return right;

    }
    if(left==right){
        //�����ظ�Ԫ��
        return left;
    }
    //������ֵ
    int mid=(left+right)/2;
    //������Ԫ�ظ���
    int ele_count=0;
    //�����󲿷�
    for(int i=0;i<len;i++){
        if(numbers[i]<=mid && numbers[i]>=left){
            ele_count++;
        }
    }
    if(ele_count>(mid-left+1)){
       return  getDuplication(numbers,len,left,mid);
    }
    //�����Ҳ���
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
/// 2 �滻�ַ����е��ַ�����%20�滻�ַ����еĿո�
//����һ
//�Ӻ���ǰ���ҿո����ƶ��ַ����滻��ʱ�临�Ӷ�ΪO(n)����ǰ���Ļ�ʱ�临�Ӷ�ΪO(n^2)
string replace_string(string str){
    //����ո�����
    int i=0,sum=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            sum++;
        }
        i++;
    }
    int c=0;                      //�ո�ĸ���
    string tmp=string(2*sum,' ');      //Ϊstr���ӿռ�ʹ�õĿ��ַ���
    str+=tmp;
    for(string::iterator i=str.end();i>=str.begin();i--){
        if(*i==' '){
            c++;
            //�ƶ��ַ���jΪ�ַ�����βָ��
            string::iterator j=(str.end())+2*(c-1);
            while(j!=i){
                *(j+2)=*j;
                j--;
            }
            //��ֵ%20
            *i='%';*(i+1)='2';*(i+2)='0';
        }
    }
    return str;
}




