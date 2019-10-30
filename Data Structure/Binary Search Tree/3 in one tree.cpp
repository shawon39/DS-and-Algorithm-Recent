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

void inOrder(node *temp)
{
    if( temp != NULL )
    {
        inOrder(temp->left);
        cout << temp->data << " ";
        inOrder(temp->right);
    }
}

void postOrder(node *temp)
{
    if( temp != NULL )
    {
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data << " ";
    }
}

int searchData(node *temp, int key)
{
    if( temp == NULL ) return 0;
    if( temp->data == key ) return 1;

    if( temp->data > key ) searchData(temp->left, key);
    else searchData(temp->right, key);
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
    preOrder(root); puts("");
    inOrder(root);  puts("");
    postOrder(root);  puts("");

    searchData(root, 5) ? cout << "found " << endl : cout << "Not found" << endl;

    return 0;
}
