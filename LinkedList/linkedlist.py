class node:
    def __init__(self,data):
        self.data=data
        self.next=None
    
class LinkedList:
    def __init__(self):
        self.head=None
    def listLength(self):
        count=0
        temp=self.head
        while(temp):
            count+=1
            temp=temp.next
        return count
    def listItems(self):
        temp=self.head
        if(self.head==None):
            print("Empty LinkedList\n")
            return
        while(temp):
            print(temp.data,)
            temp=temp.next
    def insert(self,data,position):
        count=1
        current=self.head
        temp=LinkedList()
        newNode=node(data)
        if(position==1):
            self.head=newNode
        else:
            while(current!=None and count<position):
                count+=1
                temp=current
                current=current.next    
        temp.next=newNode
        newNode.next=current
    def delete(self,position):
        count=1
        current=self.head
        temp=LinkedList()

        if(position==1):
            current=current.next
            del(self.head)
            self.head=current
        else:
            while(current!=None and (count<position)):
                temp=current
                current=current.next
            temp.next=current.next.next
            del(current)
    def findelement(self,data):
        temp=self.head
        count=1
        while(temp!=None):
            if(temp.data==data):
                print("element found at position :",count)
                return
            count+=1
            temp=temp.next
        
        print("element not found")
        return
    
if __name__=="__main__":
    llist = LinkedList()
    llist.insert(5,1)
    llist.insert(4,1)
    llist.insert(3,1)
    llist.insert(2,1)
    llist.insert(1,1)

    print(llist.listLength(),"\n")
    llist.listItems()
