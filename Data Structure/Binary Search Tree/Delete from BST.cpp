#include <bits/stdc++.h>
using namespace std;

typedef struct Tree {
    int data;
    struct Tree *left, *right;
}node;

node *root=NULL, *newnode;

node *get_node()
{
    newnode = (node*) malloc(sizeof(node));
    cin >> newnode->data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insertData(node *tempRoot, node *newnode)
{
    if( tempRoot->data > newnode->data ) {
        if( tempRoot->left == NULL ) tempRoot->left = newnode;
        else insertData(tempRoot->left, newnode);
    }
    else {
        if( tempRoot->right == NULL ) tempRoot->right = newnode;
        else insertData(tempRoot->right, newnode);
    }
}

void preOrder(node *temp)
{
    if( temp != NULL )
    {
        cout << temp->data << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

node *findMinNode(node *current)
{
    if( current->left == NULL ) {
        return current;
    }
    else return findMinNode(current->left);
}

node *deleteNode(node *current, int value)
{
    if( current == NULL ) return NULL;
    else if( current->data > value ) current->left = deleteNode(current->left, value);
    else if( current->data  < value) current->right = deleteNode(current->right, value);
    else{
        if( current->left == NULL && current->right == NULL ) {
            current = NULL;
        }
        else if( current->left == NULL ) {
            current = current->right;
        }
        else if( current->right == NULL ) {
            current = current->left;
        }
        else {
            node *temp = findMinNode(current->left);
            current->data = temp->data;
            current->left = deleteNode(current->left, temp->data);
        }
    }
}

int main()
{
    cout << "Length: ";
    int n; cin >> n;
    while(n--)
    {
        newnode = get_node();
        if( root == NULL ) root = newnode;
        else insertData(root, newnode);
    }
    puts(""); preOrder(root); puts(""); puts("");

    deleteNode(root,8);

    preOrder(root); puts("");

    return 0;
}

