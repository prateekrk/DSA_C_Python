#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ArrayStack{
    int top;
    int capacity;
    int * array;
};

struct ArrayStack * Createstack(){
    struct ArrayStack *s=(struct ArrayStack*)malloc(sizeof(struct ArrayStack));
    s->top=-1;
    s->capacity=1;
    s->array=malloc(s->capacity*sizeof(int));
    return s;
}

bool isStackEmpty(struct ArrayStack *s){
    return (s->top==-1);
}
bool isStackFull(struct ArrayStack *s){
    return (s->top==s->capacity-1);
}
void push(struct ArrayStack *s,int data){
    if(!s){
        printf("%s\n","Does not exist");
        return;
    }
    if(isStackFull(s)){
        printf("%s\n","Stack is full");
        return;
    }
    s->array[++s->top]==data;

}
int pop(struct ArrayStack * s){
    if(isStackEmpty(s))
    {
        printf("%s\n","Stack is empty");
        return 0;
    }
    return (s->array[s->top--]);
}
void stackElements(struct ArrayStack * s){
    while(s->capacity>0){
        printf("%d",s->array[++s->top]);
        s->capacity--;
    }
}
int main(){
    Createstack();
    push(s,5);
    push(s,4);
    push(s,3);
    push(s,2);
    push(s,1);
    printf("%d",pop(s));
    stackElements(s);
}