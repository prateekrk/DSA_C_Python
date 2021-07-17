#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * head=NULL;

void insertAtPosition(int data,int position){
    struct Node * current=head;
    struct Node * newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node * temp;
    newNode->data=data;
    int k=0;
    if(head==NULL){
        head=newNode;
        return;
    }
    if(position==0){
        newNode->next=current;
        head=newNode;
        return;
    }
    else{
        while(current!=NULL && k<position){
            k++;
            temp=current;
            current=current->next;
        }
        temp->next=newNode;
        newNode->next=current;
    }

}
int listCount(){
    struct Node * current=head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}
void findElement(int position){
    int x;
}

void main(){
    insertAtPosition(5,0);
    insertAtPosition(6,0);
    insertAtPosition(7,0);
    printf("%d",listCount());
}
