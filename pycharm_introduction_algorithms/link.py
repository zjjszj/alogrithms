#链表

#双向链表
class DLNode:
    def __init__(self,data=None):
        self.data=data
        self.prior=None
        self.next=None

class DoubleLinkQueue:
    def __init__(self,head=None,tail=None):
        self.head=head
        self.tail=tail

    def insert2Head(self,x):
        node=DLNode(x)
        node.next=self.head
        node.prior=None
        if self.head!=None:
            self.head.prior=node
        self.head=node

    def visitAll(self):
        p=self.head
        while p:
            print(p.data)
            p=p.next



dlq=DoubleLinkQueue()
dlq.insert2Head(3)
dlq.insert2Head(4)
dlq.visitAll()