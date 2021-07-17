#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * head =NULL;

void push(int data){
    
    struct Node * current=head;
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=current;
    head=newNode;

}
bool isStackEmpty(){
    struct Node * current=head;
    if(current==NULL){   
        return true;
    }
    return false;
}
int pop(){
    struct Node * current=head;
    struct Node * temp=NULL;
    if(isStackEmpty()){
        printf("%s","stack is empty");
        return 0;
    }
    temp=current;
    current=current->next;
    head=current;
    free(temp);
}

int Top(){
    return head->data;
}

void stackElements(){
    struct Node * current=head;
    while(current!=NULL){
        
        printf("%d",current->data);
        current=current->next;
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    pop();
    stackElements();
}