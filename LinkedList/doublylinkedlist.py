class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None
class DLL:
    def __init__(self):
        self.head=None
    def printElements(self):
        current=self.head
        while(current):
            print(current.data)
            current=current.next
    def listLength(self):
        current=self.head
        count=0
        while(current):
            count+=1

            current=current.next
    
        return count
    def insert(self,data,position):
        k=1
        current=self.head
        newNode=Node(data)
        if(position==1):
            newNode.next=current
            newNode.prev=None
            self.head=newNode
            return
        while(current.next!=None and k<(position-1)):
            k+=1
            current=current.next
        newNode.next=current.next
        newNode.prev=current
        if(current.next):
            current.next.prev=newNode
        
        current.next=newNode
if __name__ =="__main__":
    dll=DLL()
    dll.insert(5,1)
    dll.insert(2,1)
    dll.insert(3,2)
    dll.printElements()


