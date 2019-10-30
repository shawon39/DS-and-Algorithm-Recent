#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;

}node;

node* head=NULL;

void insert_any_position(int data)
{
    int cnt=1,n;
    cout << "Enter the position: ";
    cin >> n;
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(n==1) {
        newnode->next=head;
        head=newnode;
    }
    else {
        node*current=head;
        while(cnt<n-1) {
            current=current->next;
            cnt++;
        }
        newnode->next=current->next;
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
    insert_any_position(5); printData();
    insert_any_position(10); printData();
    insert_any_position(15); printData();
    insert_any_position(20); printData();
    insert_any_position(25); printData();
}



