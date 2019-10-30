#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;

}node;

node* head=NULL, *tail;

void insert_beginning(int data)
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


void printData()
{
    node*current=head;
    printf("New list is: ");
    while(current!=NULL) {
        printf("%d ", current->data);
        current=current->next;
    }
    printf("\n");
}

void printData2()
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
    insert_beginning(5);
    insert_beginning(10);
    insert_beginning(15);
    insert_beginning(20);
    insert_beginning(25);
    printData();
    printData2();
    return 0;
}
