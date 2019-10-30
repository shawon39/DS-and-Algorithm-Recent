#include <bits/stdc++.h>
using namespace std;

int main()
{
    int adj[1005][1005]={0};

    int nodes, edges, q;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++) {
        int x,y; cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    cin >> q;
    while(q--)
    {
        int a,b; cin >> a >> b;

        if( adj[a][b] == 1 ) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}


