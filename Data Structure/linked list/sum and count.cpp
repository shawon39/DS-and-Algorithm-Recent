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

void sum()
{
    node* current=head;
    int sum=0;
    while(current!=NULL){
        sum+=current->data;
        current=current->next;
    }
    printf("Sum Of Total Elements: %d\n",sum);
}
void countElements()
{
    node* current=head;
    int cnt=0;
    while(current!=NULL)
    {
        cnt++;
        current=current->next;
    }
    printf("Total Elements Left: %d\n",cnt);
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
    insert_beginning(5);
    insert_beginning(10);
    insert_beginning(15);
    insert_beginning(20);
    insert_beginning(25);
    printData();
    countElements();
    sum();
}






