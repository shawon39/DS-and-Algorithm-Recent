#include <bits/stdc++.h>
using namespace std;

#define maxx 100005

vector<int> adj[maxx];
int visited[maxx];

int dfs(int src)
{
    visited[src] = 1;
    for( auto x : adj[src] ) {
        if( !visited[x] ) {
            dfs(x);
        }
    }
}

int main()
{
    int nodes, edges; cin >> nodes >> edges;

    for(int i=0; i<edges; i++) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int head; cin >> head;
    dfs(head);
    int cnt = 0;
    for(int i=1; i<=nodes; i++)
    {
        if( !visited[i] ) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
