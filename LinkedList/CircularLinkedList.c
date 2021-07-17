#include<stdio.h>
#include<stdlib.h>

int listCount();
void printElements();

struct Node{
    int data;
    struct Node* next;
};

struct Node * head = NULL;

void insertAtPosition(int data,int position){
    int k=0;
    struct Node * current= head;
    struct Node * newNode=(struct Node*)malloc(sizeof (struct Node));
    struct Node * temp;
    newNode->data=data;
    newNode->next=newNode;


    if(head==NULL){
        head=newNode;
        return;
    }
    if(position==0){
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    if(position==listCount()) {
        while(current->next!=head){
            current=current->next;
        }
        current->next=newNode;
        newNode->next=head;
        return;
    }
    else{
        while(current!=NULL && k<(position)){
            k++;
            temp=current;
            current=current->next;
        }
        temp->next=newNode;
        newNode->next=current;

    }

}
void deleteElement(int position){
    int k=0;
    struct Node * current=head;
    struct Node * temp=head;
    struct Node * temp2;
    if(head==NULL){
        printf("%s","List is empty");
        return;
    }
    if(position==0){
        while(current->next!=head){
            current=current->next;

        }
        current->next=head->next;
        head=head->next;
        free(temp);
        return;

    }
    if(position==listCount()){
        while(current->next!=head){
            temp2=current;
            current=current->next;
        }
        temp2->next=head;
        free(current);
        return;
    }
    else{
        while(k<position){
            k++;
            temp2=current;
            current=current->next;
        }
        temp2->next=current->next;
        free(current);
        return;
    }
}

void printElements(){
    struct Node * current=head;
    if(head==NULL){
        printf("%s","No elements");
        return;
    }
    printf("\n");
    do{
            printf("%d ",current->data);
            current=current->next;
        }while(current!=head);

}
int listCount(){
    struct Node * current=head;
    int count=0;
    if(current==NULL) {
        printf("%s","List is empty");
        return 0;
    }
    do{
        count++;
        current=current->next;
    }while(current!=head);
    return count;
}

int main(){
    insertAtPosition(4,0);
    insertAtPosition(5,0);
    insertAtPosition(6,2);
    printElements();

    insertAtPosition(7,3);
    printf("\nList Count = %d",listCount());
    printElements();
    deleteElement(1);
    printf("\nList Count = %d",listCount());
    printElements();
    return 0;
}