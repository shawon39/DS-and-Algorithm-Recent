// Directed Graph

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int adj[10][10]={0};

    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++) {
        int x,y; cin >> x >> y;
        adj[x][y] = 1; //Directed Graph
        //adj[y][x] = 1; //If both cases works then it will be Undirected Graph
    }

    for(int i=1;  i<=nodes; i++) {
        cout << i << " -> ";
        for(int j=1; j<=nodes; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

