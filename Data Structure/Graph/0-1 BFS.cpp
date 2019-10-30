#include <bits/stdc++.h>
using namespace std;

// node maximum = 100

int n,e,start;
vector< pair<int,int> >edges[100];
int dist[100];

int zeroOneBFS(int s)
{
    for(int i=1; i<=n; i++) {
        dist[i] = INT_MAX;
    }

    deque <int> Q;
    Q.push_back(s);
    dist[s] = 0;

    while( !Q.empty() )
    {
        int v = Q.front();
        Q.pop_front();

        for(int i=0; i<edges[v].size(); i++) {

            if( dist[ edges[v][i].first ] > dist[v] + edges[v][i].second ) {
                dist[ edges[v][i].first ] = dist[v] + edges[v][i].second;

                if( edges[v][i].second == 0 ) {
                    Q.push_front( edges[v][i].first );
                }
                else {
                    Q.push_back( edges[v][i].first );
                }
            }
        }
    }
}

int main()
{
    // n = nodes, e = edges
    cin >>n>>e>>start;

    for(int i=1; i<=e; i++) {
        int x,y,wt;
        cin >>x>>y>>wt;
        edges[x].push_back( make_pair(y,wt) );
        edges[y].push_back( make_pair(x,wt) );
    }

    zeroOneBFS(start);

    for(int i=0; i<=n; i++) {
        cout << i << " -> " << dist[i] << endl;
    }
    return 0;
}

/*
8 13 0
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
7 8 1
*/
