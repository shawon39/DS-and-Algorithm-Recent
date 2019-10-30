#include <bits/stdc++.h>
using namespace std;

#define maxx 1000

vector <int> adj[maxx];
int visited[maxx];

int dfs(int s)
{
    visited[s] = 1;

    for( auto x : adj[s] )
    {
        if( !visited[x] ) {

            cout << x << " ";
            dfs(x);
        }
    }
}

int main()
{
    int e,start;
    cin>>e>>start;

    for(int i=0; i<e; i++) {
        int x,y; cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(start);
}
