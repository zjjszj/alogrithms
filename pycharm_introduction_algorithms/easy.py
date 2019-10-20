#选择第i小的元素，O(n)
#使用快速排序的思想，但是只用比较一边
import random

#划分主元素
# def randomized_partition_1(A,p,r):
#     length=len(A)
#     ran=random.randint(p,r)
#     print('ran=',ran)
#     key=A[ran]
#     #交换第一个元素与主元素
#     tmp=A[p]
#     A[p]=key
#     A[ran]=tmp
#     while r>p:
#         while r > p and A[r] >= key:
#             r=r-1
#         if r>p:
#             A[p] = A[r]
#         while r > p and A[p] <=key:
#             p=p+1
#         if r>p:
#             A[r] = A[p]
#     A[r]=key
#     return r
#
# #交换函数
# def exchange(A,i,j):
#     tmp=A[i]
#     A[i]=A[j]
#     A[j]=tmp
#
# def randomized_partition_2(A,p,r):
#     ran=random.randint(p,r)
#     #尾元素作为主元素
#     key=A[ran]
#     exchange(A,ran,r)
#     i=p-1         #指向最后一个小于主元素的元素
#     for j in range(p,r):
#         if A[j]<key:
#             i=i+1
#             #交换A[i]与A[j]
#             exchange(A,i,j)
#     #交换A[r]与A[i+1]
#     exchange(A,r,i+1)
#     return i+1
#
# def randomized_select(A,p,r,i):
#     if p==r:return A[p]
#     #计算主元素左边元素的个数
#     index=randomized_partition_2(A,p,r)
#     nums=index-p+1
#     if nums==i:return A[index]
#     elif nums>i:return randomized_select(A,p,index-1,i)
#     else: return randomized_select(A,index+1,r,i-nums)
#
# a=[1,4,9,2,5,7]
# b=randomized_select(a,0,5,4)
# print(b)



