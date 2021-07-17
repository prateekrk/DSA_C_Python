#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int data;
    struct  ListNode * next;
}node;
struct ListNode *head=NULL;

int listLength(){
    struct ListNode * current=head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}
void insertAtPosition(int data,int position){
    struct ListNode * current=head;
    struct ListNode * temp=NULL;
    struct ListNode * newNode=(struct ListNode*)malloc(sizeof (struct ListNode));
    newNode->data=data;
    int count=1;
    if(position==1){
        newNode->next=current;
        head=newNode;
    }
    else{
        while((current!=NULL) && (count<position)){
            count++;
            temp=current;
            current=current->next;
        }
        temp->next=newNode;
        newNode->next=current;
    }
}
void listItems(){
    struct ListNode * current=head;
    
     if(head==NULL){
        printf("\n%s","No items in list");
        return;
    }
    printf("\n%s","List Items:");
    while(current!=NULL){
        printf(" %d",current->data);
        current=current->next;
    }
}
void deleteItem(int position){
    struct ListNode * current=head;
    struct ListNode* temp=NULL;
    int count=1;
    if(head==NULL){
        printf("\n%s","No items in list");
        return;
    }
    if(position==1){
        current=current->next;
        free(current);
    }
    else{
        while(current!=NULL && count<position){
            count++;
            temp=current;
            current=current->next;
        }
        temp->next=current->next;
        free(current);
    }
}
void DeleteList(){
    struct ListNode * auxilaryNode,*iterator;
    iterator=head;

    while(iterator){
        auxilaryNode=iterator->next;
        free(iterator);
        iterator=auxilaryNode;
    }
    head=NULL;

}
void findElementFromEnd(int position){
    struct ListNode * current=head;
    struct ListNode * temp;
    int num=listLength()-position;
    int k=0;
    while(current!=NULL && k<(num)){
        k++;
        current=current->next;

    }
    printf("%d",current->data);
}
void listReverse(){
    struct ListNode * current=head;\\
            temp=current;
            current=current->next;
        }
        temp->next=current->next;
        
        printf("%d",current->data);
        k--;
        
       
    }
    
}
int main(){
    insertAtPosition(1,1);
    insertAtPosition(2,2);
    insertAtPosition(3,3);
    insertAtPosition(4,4);
    insertAtPosition(5,5); 

    listReverse();
    listItems();

}