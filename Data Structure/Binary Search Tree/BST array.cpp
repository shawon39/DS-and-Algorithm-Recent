#include <bits/stdc++.h>
using namespace std;

#define SIZE 50
int tree[SIZE];

void insertData(int data, int index)
{
    if( index >= SIZE ) {
        printf("Space not available :( \n");
        return;
    }
    else {
        if( tree[index] == -1 ) {
            tree[index] = data;
            return;
        }
        else {
            if( tree[index] > data ) insertData( data, index*2 +1 );
            else insertData( data, index*2 +2 );
        }
    }
}

int searchData(int data, int index)
{
    if( tree[index] == -1  ) return 0;
    if( tree[index] == data ) return 1;

    if( tree[index] > data ) searchData(data, index*2+1);
    else return searchData(data, index*2+2);
}

int main()
{
    fill_n(tree, SIZE, -1);

    cout << "Enter Total Data: ";
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the value: ";
        int data; cin >> data;
        insertData(data,0);
    }

    for(int i=0; i<SIZE; i++) {
        printf("tree[%d] = %d\n",i, tree[i]);
    }

    int x = searchData(5,0);
    x ? puts("Found!") : puts("Not Found!");
}
