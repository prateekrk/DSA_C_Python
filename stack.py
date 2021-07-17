class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class Stack:
    def __init__(self):
        self.top=None
    def push(self,data):
        newNode=Node(data)
        newNode.next=self.top
        self.top=newNode
    def isEmpty(self):
        return self.top==None
    def pop(self):
        current=self.top
        temp=current
        current=current.next
        self.top=current
        del(temp)
    def stackElements(self):
        current=self.top
        if(self.isEmpty()):
            print("Stack is empty")
            return
        while(current):
            print(current.data," ")
            current=current.next

if __name__=="__main__":
    s=Stack()
    s.push(5)
    s.push(4)
    s.push(3)
    s.push(2)
    s.push(1)
    
    s.stackElements()
    s.pop()
    print("after pop:")
    s.stackElements()