# 1 使用队列实现栈操作
# from collections import deque
# class MyStack(object):
#
#     def __init__(self):
#         """
#         Initialize your data structure here.
#         """
#         self.queue = deque()
#
#     def push(self, x):
#         """
#         Push element x onto stack.
#         :type x: int
#         :rtype: None
#         """
#         length = len(self.queue)
#         self.queue.append(x)
#         for _ in range(length):
#             self.queue.append(self.queue.popleft())
#
#     def pop(self):
#         """
#         Removes the element on top of the stack and returns that element.
#         :rtype: int
#         """
#         return self.queue.popleft()
#
#     def top(self):
#         """
#         Get the top element.
#         :rtype: int
#         """
#         return self.queue[0]
#
#     def empty(self):
#         """
#         Returns whether the stack is empty.
#         :rtype: bool
#         """
#         return not self.queue

#