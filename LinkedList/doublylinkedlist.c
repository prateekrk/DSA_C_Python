#include<stdio.h>
#include<stdlib.h>

typedef struct  DLLNode{
    int data;
    struct DLLNode * next;
    struct DLLNode * prev;
}DLLNode;

struct DLLNode * head=NULL;

void insert(int data,int position){
    int k=1;
    struct DLLNode * current=head;
    
    
    struct DLLNode * newNode=(struct DLLNode*)malloc(sizeof(struct DLLNode));
    newNode->data=data;
    if(position==1){
        newNode->next=current;
        newNode->prev=NULL;
       if(current){
           current->prev=newNode;
       }
        head=newNode;
        return;
    }
    while(k<(position-1) && current->next!=NULL){
        current=current->next;
        k++;
    }
    newNode->next=current->next;
    newNode->prev=current;
    if(current->next){
        current->next->prev=newNode;
    
    }
    current->next=newNode;
    return;
}
void delete(int position){
    struct DLLNode * current=head;
    struct DLLNode * temp;
    int k=1;
    if(position==1){
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(current);
        return;
    }
    while((k<position) && current->next!=NULL){
        current=current->next;
        k++;
    }
    if(k!=(position-1)){
        printf("%s","Node does not exist");
        return;
    }
    temp=current->prev;
    temp->next=current->next;
    if(current->next){
        current->next->prev=temp;
    }
    free(current);
    return;
}
int listLength(){
    struct DLLNode * current=head;
    int count=0;
    if(current==NULL){
        printf("%s","List is empty");
        return 0;
    }
    while(current){
        count++;
        current=current->next;
    }
    return count;
}
void printElements(){
    struct DLLNode * current=head;
    if(current==NULL){
        printf("%s","List is empty");
        return;
    }
    while(current){
        printf("%d ",current->data);
        current=current->next;
    }
}
int main(){
    insert(1,1);
    insert(2,1);
    insert(3,2);
    delete(3);
    printElements();
    printf("%d",listLength());
}