#include <bits/stdc++.h>
using namespace std;

vector <int> v[10];
bool vis[10];

void bfs(int s)
{
    queue <int> q;
    q.push(s);
    vis[ s ] = true;
    cout << v[p][i] << " ";
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0; i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ] ] == false)
            {
                q.push(v[ p ][ i ]);
                vis[ v[ p ][ i ] ] = true;
                cout << v[p][i] << " ";
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++) {
        int x,y; cin >> x >> y;
        v[x].push_back(y);
    }
    bfs(0);
}
