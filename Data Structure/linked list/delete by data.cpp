#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;

}node;

node* head=NULL;

void insert_beginning(int data)
{
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}

void delete_by_data()
{
    int n;
    node* current=head;
    node* previous;
    cout << "Which data you want to delete: ";
    cin >> n;
    if(head->data==n) {
        head=head->next;
        free(current);
    }
    else {
        while(current!=NULL && current->data!=n) {
            previous=current;
            current=current->next;
        }
        if(current!=NULL) {
            previous->next=current->next;
            free(current);
        }
        else {
            cout << "Data is not found !" << endl;
        }
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
    insert_beginning(5); printData();
    insert_beginning(10); printData();
    insert_beginning(15); printData();
    insert_beginning(20); printData();
    insert_beginning(25); printData();
    delete_by_data(); printData();
}



