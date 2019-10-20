import math
#手动设置递归的最大深度
import sys
sys.setrecursionlimit(100000)
import numpy as np

#最大子数组
#分治算法
def find_max_cross_subarray(l,i,j):
    mid=math.floor((i+j)/2);left_max=l[mid];right_max=l[mid+1];left_sum=right_sum=0;left=mid;right=mid+1
    for i in range(mid,-1,-1):
        left_sum=left_sum+l[i]
        if left_sum>left_max:
            left_max=left_sum
            left=i

    for i in range(mid+1,len(l),1):
        right_sum=right_sum+l[i]
        if right_sum>right_max:
            right_max=left_sum
            right=i
    return left,right,left_max+right_max



def find_max_subarray(l,i,j):
    #解决
    if i==j:
        return i,j,l[i]
    else:
    #分解
        mid=math.floor((i+j)/2)
        left_i,left_j,left_max=find_max_subarray(l,i,mid)
        right_i,right_j,right_max=find_max_subarray(l,mid+1,j)
        cross_i,cross_j,cross_max=find_max_cross_subarray(l,i,j)
    #合并
    if left_max>=right_max and left_max>=cross_max:
        return left_i,left_j,left_max
    if right_max>=left_max and right_max>=cross_max:
        return right_i,right_j,right_max
    if cross_max>=left_max and cross_max>=right_max:
        return cross_i,cross_j,cross_max



#i,j,_max=find_max_subarray([0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7],0,16)
#print("最大子数组的索引为从{0}到{1},值为{2}".format(i,j,_max))


