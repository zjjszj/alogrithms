#include <iostream>
#include<vector>

#include "intermediate.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;

// 1 从长度为n+1的数组（元素只能为1-n）中返回任意一个重复数字,不能修改元素内容
int getDuplication(int *numbers,int len,int left,int right);
// 2 替换字符串中的字符：用%20替换字符串中的空格
string replace_string(string str);


int main()
{
    // 1 查找重复元素
//    int arr[4]={2,3,3,2};
//    int len=4;
//    int result;
//    result=getDuplication(arr,len,1,len-1);
//    std::cout<<"重复元素是："<<result<<std::endl;
    // 2 字符串替换
//    string str="happy new year!";
//    str=replace_string(str);
//    cout<<str;

    ///链表
    List l1;
    //添加节点到尾节点
    l1.addToTail(1);
    l1.addToTail(2);
    l1.addToTail(3);
    l1.addToTail(4);
    //遍历链表
    l1.visitAll();
    l1.printListReverse();





    return 0;
}
