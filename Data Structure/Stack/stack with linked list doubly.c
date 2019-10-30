#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;

}node;

node* head=NULL, *tail;

void push(int data)
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL) {
        tail=newnode;
        head=newnode;
    }
    else {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void pop()
{
    if(head == NULL) {
        printf("Stack is Empty !\n");
    }
    else if(head->next == NULL) {
        head = NULL;
    }
    else {
        node *temp = head;
        head = head->next;
        head->prev=NULL;
        free(temp);
    }
}

void print()
{
    node*current=head;
    printf("New list is: ");
    while(current!=NULL) {
        printf("%d ", current->data);
        current=current->next;
    }
    printf("\n");
}

void print2()
{
    node*current=tail;
    printf("New list is: ");
    while(current!=NULL) {
        printf("%d ", current->data);
        current=current->prev;
    }
    printf("\n");
}

int main()
{
    pop(); print();
    push(1); print();
    push(2); print();
    push(3); print();
    pop(); print();
    push(5); print();
    pop(); print();
    push(8); print();
    pop(); print();

    printf("\n");
    print(); print2();
    return 0;
}
