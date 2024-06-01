// used for dependencies 
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2, M = 2e5+4;

vector<int>adj[N];
bool vis[N];

void DFS(int u){
    vis[u] = true;
    for(int v: adj[u]){
        if(!vis[v]) DFS(v);
    }
    printf("%d", u);
}

int main()
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        // to opposite directions adj[v].push_back(u)
    }

    for(int u = 0; u < n; u++){
        if(!vis[u]) {
            DFS(u);
        }
    }
    return 0;
}

/*
7 8
0 2
0 1
0 5
5 2
3 2
3 4
5 4
1 3
*/