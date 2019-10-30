#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;

}node;

node* head=NULL, *tail;

void insert_any_position(int data)
{
    int cnt=1,n;
    printf("Enter the position: ");
    scanf("%d",&n);
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==NULL) {
        tail=newnode;
        head=newnode;
    }
    else if(n==1) {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    else {
        node*current=head;
        while(cnt<n-1) {
            current=current->next;
            cnt++;
        }
        if(current->next == NULL) {
            tail = newnode;
            current->next=newnode;
            newnode->prev=current;
        }
        else {
            newnode->next=current->next;
            current->next->prev=newnode;
            current->next=newnode;
            newnode->prev=current;
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
    insert_any_position(5);
    printData();
    printData2();
    insert_any_position(10);
    printData();
    printData2();
    insert_any_position(15);
    printData();
    printData2();
    insert_any_position(20);
    printData();
    printData2();
    insert_any_position(25);
    printData();
    printData2();
    return 0;
}


