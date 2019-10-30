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

void searchData()
{
    node* current=head;
    int key, check=0;

    printf("Enter the search data: ");
    cin >> key;

    while(current!=NULL) {
        if(current->data==key) {
            check = 1;
            break;
        }
        current=current->next;
    }
    if(check==1) printf("Found");
    if(check==0) printf("Not Found");
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
    searchData();
}






