#include <bits/stdc++.h>
using namespace std;

vector <int> v[10];
bool vis[10];
int level[10];

void bfs(int s)
{
    queue <int> q;
    q.push(s);
    vis[ s ] = true;
    level[s] = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0; i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ] ] == false)
            {
                level[ v[p][i] ] = level[p]+1;
                q.push(v[ p ][ i ]);
                vis[ v[ p ][ i ] ] = true;
            }
        }
    }
}

int main()
{
    int nodes, edges, start;
    cin >> nodes >> edges >> start;

    for(int i=0; i<edges; i++) {
        int x,y; cin >> x >> y;
        v[x].push_back(y);
    }
    bfs(start);
    for(int i=0; i<10; i++) {
        cout << i << " = " << level[i] << endl;
    }
}

