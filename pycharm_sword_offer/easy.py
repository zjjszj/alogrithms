# 1 找出数组中重复的数字
#长度为n的数组，数组元素为0-n-1
#example:长度为4[0，0，1，1] 输出为0或1
def getRepeatNumber(num_list,repeat_list):
    flag=False
    n=len(num_list)
    #遍历数组
    for i,value in enumerate(num_list):
        #为每个位置找元素
        if i!=value:
            while i!=value and value!=num_list[i]:
                #交换位置
                temp=value
                temp=num_list[i]
                num_list[i]=temp
            if value==num_list[i]:
                repeat_list.append(value)
                return True
    return flag;
    #重复的元素

# 2 从长度为n+1的数组（元素只能为1-n）中返回任意一个重复数字,不能修改元素内容
import math
def getDuplication(numbers, length, left, right):
    #判断出口条件
    if left>right:
        return right
    if left==right:
        return left
    #计算中值元素
    mid=math.floor((left+right)/2)
    #计算左半部分
        #列表中区间内元素个数
    ele_count = 0
        #计算列表中区间元素个数
    for i in range(length):
        if numbers[i]>=left and numbers[i]<=mid:
            ele_count+=1
    if ele_count>(mid-left+1):
        result=getDuplication(numbers,length,left,mid)
        return result
    #计算右半部分
    ele_count = 0
        #计算列表中区间元素个数
    for i in range(length):
        if numbers[i]>=(mid+1) and numbers[i]<=right:
            ele_count+=1
    if ele_count>(right-mid):
        result=getDuplication(numbers,length,mid+1,right)
        return result









if __name__=='__main__':
    print('========================')
    # 1 查找重复元素
    # repeat_list=[]
    # isRepeat=getRepeatNumber([2,2,1,1,2.5,10],repeat_list)
    # if(isRepeat): print('其中一个重复的元素是：',repeat_list.pop(0))

    # 2 查找重复元素
    # numbers=[2,3,2,3]
    # length=len(numbers)
    # result=getDuplication(numbers,length,1,length-1)
    # print("重复元素是：",result)















