#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2, M = 2e5+4;

vector<int>adj[N];
bool vis[N];

void DFS(int u){
    vis[u] = true;
    for(int v: adj[u])
        if(!vis[v]) DFS(v);
}

int main()
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int connected_components = 0;
    for(int u = 0; u < n; u++){
        if(!vis[u]) {
            connected_components++;
            DFS(u);
        }
    }
    // take care of starting node 0 or 1
    puts(connected_components == 1 && m == n-1? "YES\n": "NO\n");
    return 0;
}
