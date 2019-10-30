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

void update_data_by_position(int data)
{
    node* current=head;
    int cnt=1,n;
    cout << "Enter the update position: ";
    cin >> n;
    while(cnt<n)
    {
        current=current->next;
        cnt++;
    }
    current->data=data;
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
    update_data_by_position(100); printData();
}





