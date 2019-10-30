// Directed Graph

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int adj[10][10]={0};
    memset(adj, -1, sizeof(adj[0][0]) * 10 * 10);

    int nodes = 10;

    for(int i=1;  i<nodes; i++) {
        cout << i << " -> ";
        for(int j=1; j<nodes; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


