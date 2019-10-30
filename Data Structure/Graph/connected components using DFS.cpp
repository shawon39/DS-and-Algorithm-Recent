#include <bits/stdc++.h>
using namespace std;

#define maxx 7

vector <int> adj[maxx];
int visited[maxx];

int dfs(int s)
{
    visited[s] = 1;
    for( auto x : adj[s] )
    {
        if( !visited[x] ) {
            dfs(x);
        }
    }
}

int main()
{
    int e; cin>>e;

    for(int i=0; i<e; i++) {
        int x,y; cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int cnt = 0;
    for(int i=1; i<=6; i++) {
        if( !visited[i] ) {
            dfs(i);
            cnt++;
        }
    }
    cout << "Connected Components: " << cnt << endl;
    return 0;
}
