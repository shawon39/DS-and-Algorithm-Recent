// Directed Graph

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>adj[10];

    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y); // Directed Graph
        // adj[y].push_back(x); //If both cases works then it will be Undirected Graph
    }

    for(int i=1;  i<=nodes; i++) {
        cout << i << " -> ";
        for(int j=0; j<adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
