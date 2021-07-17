class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class CLL:
    def __init__(self):
        self.head=None
    def insertElement(self,data):
        current=self.head
        newNode=Node(data)
        newNode.next=self.head
        if(self.head is not None):
            while(current.next!=self.head):
                current=current.next
            current.next=newNode
        else:
            newNode.next=newNode
        self.head=newNode
            
        
    def printElements(self):
        current=self.head
        if(self.head==None):
            print("List is empty")
            return
        print("Elements : ")

        if(self.head is not None):
            while(True):
                print(current.data," ")
                current=current.next
                if(current==self.head):
                    break
            
    def listCount(self):
        current=self.head
        count=0
        if(self.head==None):
            print("List is empty")
            return
        
        print("List length:")
        while(current.next!=self.head):
            count+=1
            current.next=current
           
        
        return count

if __name__ =="__main__":
    cll=CLL()
    cll.insertElement(5)
    cll.insertElement(6)
    cll.insertElement(7)
    print(cll.listCount())

    cll.printElements()
