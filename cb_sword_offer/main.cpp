#include <iostream>
#include<vector>

#include "intermediate.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;

// 1 �ӳ���Ϊn+1�����飨Ԫ��ֻ��Ϊ1-n���з�������һ���ظ�����,�����޸�Ԫ������
int getDuplication(int *numbers,int len,int left,int right);
// 2 �滻�ַ����е��ַ�����%20�滻�ַ����еĿո�
string replace_string(string str);


int main()
{
    // 1 �����ظ�Ԫ��
//    int arr[4]={2,3,3,2};
//    int len=4;
//    int result;
//    result=getDuplication(arr,len,1,len-1);
//    std::cout<<"�ظ�Ԫ���ǣ�"<<result<<std::endl;
    // 2 �ַ����滻
//    string str="happy new year!";
//    str=replace_string(str);
//    cout<<str;

    ///����
    List l1;
    //��ӽڵ㵽β�ڵ�
    l1.addToTail(1);
    l1.addToTail(2);
    l1.addToTail(3);
    l1.addToTail(4);
    //��������
    l1.visitAll();
    l1.printListReverse();





    return 0;
}
