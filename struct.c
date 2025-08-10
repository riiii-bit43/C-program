#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* stack_top= NULL;
struct Node* root= NULL;
void push(int);
void pop(void);
void peek(void);

int main(){
    int ch,data;
    while(1){
        printf("enter your choice:");
        printf("\n1. push\n2. pop\n3. peek\n4. exit");
        scanf("%d",&ch);
        switch(ch){
            case1:
            printf("enter data to push in stack:");
            scanf("%d",&data);
            push(data);
            break;
            case2:
            pop();
            break;
            case3:
            peek();
            break;
            case4:
            exit(0);
        }
    }
    return 0;
}
void push(int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data= data;
    newNode->next= NULL;
    if(stack_top== NULL){
        stack_top= newNode;
        root= newNode;
    }
    else{
        stack_top->next= newNode;
        stack_top = newNode;
    }
}
void pop(){
    if(stack_top== NULL){
        printf("stack underflow");
    }
    else{
        if(root== stack_top){
            printf("pop data at top:%d",stack_top->data);
            root= stack_top= NULL;
        }
        else{
            struct Node* temp= root;
            while(temp->next!= stack_top){
                temp = temp->next;
            }
            printf("pop data  at the top:%d",stack_top->data);
            stack_top= temp;
        }
    }
}
void peek(){
    printf("data element at the peek:%d",stack_top->data);
}


