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

void delete_by_data()
{
    node* current=head;
    node* previous;
    printf("Which data you want to delete? ");
    int n; scanf("%d", &n);
    if(head->data == n) {
        head=head->next;
        head->prev=NULL;
        free(current);
    }
    else {
        while(current!=NULL && current->data!=n) {
            previous=current;
            current=current->next;
        }
        if(current!=NULL) {
            if(current->next == NULL) {
                previous->next = NULL;
                tail=previous;
                free(current);
            }
            else {
                previous->next=current->next;
                current->next->prev=previous;
                free(current);
            }
        }
        else {
            printf("%d is not found in the list !");
        }
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
    int i;
    printData();
    printData2();
    for(i=1; i<=5; i++) {
        delete_by_data();
        printData();
        printData2();
    }
    return 0;
}
