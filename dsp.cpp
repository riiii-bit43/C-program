#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
//beginning
void insertAtFront(int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head;
    head= newNode;
}

//end
void insertAtEnd(int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    
    if(head==NULL){
        head= newNode;
    }
    else{
        struct Node* temp= head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next= newNode;
    }
}

//middle
void insertAtMiddle(int data,int position){
    if(position<1 || position>countNodes(head)){
        printf("position invalid");
        return;
    }
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(position==1){
        newNode->next=head;
        head= newNode;
    }
    else{
        struct Node* temp= head;
        for(int i=1;i<position-1;i++){
            temp= temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

//countwp
int countNodes(struct Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

//print
void printList(){
struct Node* temp=head;
while(temp!=NULL){
    printf("%d",temp->data);
    temp= temp->next;
}
printf("\n");
}

int main()
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    
    printf("original link list:");
    printList();
    
    insertAtFront(4);
    insertAtMiddle(5,3);
    insertAtEnd(6);
    printf("Modified link list:");
    printList();
    return 0;
}






