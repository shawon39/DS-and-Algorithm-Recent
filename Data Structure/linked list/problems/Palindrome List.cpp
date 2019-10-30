#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next, *prev;

}node;

node *head=NULL, *tail=NULL;

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
        tail = newnode;
    }
}
void check_palindrome()
{
    int f = 0;
    node*start=head;
    node*last=tail;

    while(start!=last) {
        if( start->data != last->data ) {
            f = 1;
            break;
        }
        start=start->next;
        last=last->prev;

        if( start->next == last ) break;
    }
    if( f ) cout << "Not palindrome" << endl;
    else cout << "Palindrome" << endl;
}

int main()
{
    insert_end(5);
    insert_end(6);
    insert_end(10);
    insert_end(6);
    insert_end(5);
    check_palindrome();
}


