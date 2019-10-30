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

void delele_by_position()
{
    node*current=head;
    node*previous;
    int cnt=1,n;
    cout << "Enter the position: ";
    cin >> n;
    if(n==1) {
        head=head->next;
        free(current);
    }
    else {
        node*current=head;
        while(cnt<n) {
            previous=current;
            current=current->next;
            cnt++;
        }
        previous->next=current->next;
        free(current);
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
    delele_by_position(); printData();
}




