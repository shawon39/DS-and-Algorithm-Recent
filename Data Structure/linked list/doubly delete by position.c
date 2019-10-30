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

void delele_by_position()
{
    node*current=head;
    node*previous;
    int cnt=1,n;
    printf("Enter the position: ");
    scanf("%d", &n);
    if(n==1) {
        head=head->next;
        head->prev=NULL;
        free(current);
    }
    else {
        node*current=head;
        while(cnt<n) {
            previous=current;
            current=current->next;
            cnt++;
        }
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
    for(i=1; i<=5; i++) {
        delele_by_position();
        printData();
        printData2();
    }
    return 0;
}



