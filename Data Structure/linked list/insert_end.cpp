#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;

}node;

node* head=NULL;

void insert_end(int data)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;

    if(head==NULL) head=newnode;
    else {
        node* current=head;
        while(current->next!=NULL) {
            current=current->next;
        }
        current->next=newnode;
    }
}

void printData()
{
    node*current=head;
    cout << "New list is: ";
    while(current!=NULL) {
        cout << current->data << " ";
        current=current->next;
    }
    cout << endl;
}

int main()
{
    insert_end(5); printData();
    insert_end(10); printData();
    insert_end(15); printData();
    insert_end(20); printData();
    insert_end(25); printData();
}

