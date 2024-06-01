#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2, M = 2e5+4;
int n, m, u, v;

vector<int>adj[N];
int vis[N];

const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;

bool isCyclic(int u){
    vis[u] = IN_PROGRESS;
    for(int v: adj[u]){
        if(vis[v] == NOT_VISITED){
            if (isCyclic(v)) return true; // return isCyclic will close the whole thing
        }
        else if(vis[v] == IN_PROGRESS){
            return true;
        }
    }
    vis[u] = VISITED;
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    int start;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    // for multiple connected componenst

    for(int u = 0; u < n; u++){
        if(vis[u] == NOT_VISITED){
            if(isCyclic(u)) {
                puts("Cyclic");
                return 0;
            }
        }
    }
    puts("Acyclic");
    return 0;
}

/*
6 7
0 1
1 2
2 4
0 4
2 3
5 0
2 0
*/