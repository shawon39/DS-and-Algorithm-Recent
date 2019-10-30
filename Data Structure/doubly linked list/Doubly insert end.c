#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;

}node;

node* head=NULL, *tail;

void insert_end(int data)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==NULL) {
        head=newnode;
        tail=newnode;
    }
    else {
        node* current=head;
        while(current->next!=NULL) {
            current=current->next;
        }
        current->next=newnode;
        newnode->prev=current;
        tail=newnode;
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
    insert_end(5);
    insert_end(10);
    insert_end(15);
    insert_end(20);
    insert_end(25);
    printData();
    printData2();
    return 0;
}
