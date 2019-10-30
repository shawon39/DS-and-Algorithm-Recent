#include <bits/stdc++.h>
using namespace std;

#define maxx 1000

vector <int> adj[maxx];
int visited[maxx];

int dfs(int src)
{
    stack <int> st;
    st.push(src);
    visited[src] = 1;

    while( !st.empty() ) {

        int p = st.top();
        st.pop();

        for( auto x : adj[p] ) {
            if( !visited[x] ) {
                cout << x << " ";
                st.push( x );
                visited[x] = 1;
            }
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

