#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct stack{
    char data;
    struct stack * next;
};

struct stack * top=NULL;
void push(char c){
    struct stack * newNode=(struct stack *)malloc(sizeof(struct stack));
    newNode->data=c;
    newNode->next=top;
    top=newNode;

}
bool truthy(char a,char b){
    if(a=='(' && b==')'){
        return true;
    }
    if(a=='{' && b=='}'){
        return true;
    }
    if(a=='[' && b==']'){
        return true;
    }
    else{
        return false;
    }
}
void pop(){
    struct stack * current=top;
    struct stack * temp;
    
    temp=current;
    current=current->next;
    free(temp);
    top=current;
}
char onTop(){
    struct stack * current=top;
    return current->data;
}
void balance(){
    if(top==NULL){
        printf("%s","Balanced");
        return;
    }
    else{
        printf("%s","UnBalanced");
        return;
    }
}
void stackElements(){
    struct stack * current=top;
    if(top==NULL){
        printf("\n%s","stack is empty");
    }
    while(current!=NULL){
        printf("%s",current->data);
        current=current->next;
    }
}
int count(){
    struct stack * current=top;
    int count=0;
    while(current){
        count++;
        current=current->next;
    }
    return count;
}
int main(){
    char c[100];
    printf("%s","Enter paranthesis : ");
    scanf("%s",&c);
    
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='{' || c[i]=='[' || c[i]=='('){
           push(c[i]);
        }
        if(truthy(onTop(),c[i])){
            pop();
        }
        
    }
    
    int count1=count();
    if(count1>0){
        printf("%s","Unbalanced");
        return 0;
    }
    printf("%s","Balanced");
    return 0;
    
}

