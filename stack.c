#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct element{
    int data;
    struct element *next;
};

struct head {
    int size;
    struct element *next; //point to the last one
    struct element *top;  //point to the first one
};

void print_stack(struct head* stack_p);
void push(struct head* stack_p,int data);
struct element* pop(struct head *stack_p);

int main(){
    struct head stack_head;
    stack_head.size=0;
    stack_head.next=NULL;
    stack_head.top=NULL;

    int num,data;
    char command[5];
    scanf("%d",&num);
    for(int i=0;i<num;++i){
        scanf("%4s",command);
        if(strcmp(command,"push")==0){
            scanf("%d",&data);
            push(&stack_head,data);
        }else if(strcmp(command,"pop")==0){
            struct head* e=pop(&stack_head);
            free(e);
        }
    }
    print_stack(&stack_head);
}
void print_stack(struct head *stack_p){
    printf("%d\n",stack_p->size);
    for(struct element *ptr=stack_p->next;ptr!=NULL;ptr=ptr->next){
        printf("%d ",ptr->data);
    }
}

void push(struct head* stack_p,int data){
    struct element* p=malloc(sizeof(struct element));
    p->data=data;

    if(stack_p->next==NULL){
        stack_p->next=p;
    }else{
        stack_p->top->next=p;
    }
    stack_p->top=p;
    p->next=NULL;
    (stack_p->size)++;
}
struct element* pop(struct head* stack_p){
    struct element *returnVal=stack_p->top;
    struct element *prev,*curr=stack_p->next;
    (stack_p->size)--;
    if(stack_p->size==0){
        stack_p->top=NULL;
        stack_p->next=NULL;
    }else{
        while(curr->next!=stack_p->top) {
//            printf("%d", curr->data);
            curr = curr->next;
        }
        stack_p->top=curr;
        curr->next=NULL;
    }
    return returnVal;
}


