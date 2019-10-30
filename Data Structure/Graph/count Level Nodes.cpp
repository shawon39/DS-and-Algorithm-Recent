#include <bits/stdc++.h>
using namespace std;

#define maxx 100005

vector < int > adj[maxx];
int level[maxx];
int visited[maxx];
int ans = 0, lvl;

int bfs(int s)
{
    queue < int > q;
    q.push(s);
    level[s] = 1;
    visited[s] = 1;

    while( !q.empty() ) {
        int p = q.front();
        q.pop();

        for(int i=0; i<adj[p].size(); i++) {

            if( visited[ adj[p][i] ] == 0 ) {
                level[ adj[p][i] ] = level[p]+1;
                q.push( adj[p][i] );
                visited[ adj[p][i] ] = 1;

                if( level[ adj[p][i] ] == lvl  ) {
                    ans++;
                }

            }
        }
    }
}

int main()
{
    int edges; cin >> edges;
    for(int i=1; i<=edges-1; i++) {
        int x,y; cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> lvl;
    bfs(1);
    cout << ans << endl;
    return 0;
}
