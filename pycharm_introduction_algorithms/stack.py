class Stack:
    def __init__(self):
        self.items=[]

    #判空
    def empty(self):
       return not self.items
    #入栈
    def push(self,x):
        self.items.append(x)

    #出栈
    def pop(self):
        return self.items.pop()

    def print(self):
        print(self.items)



