#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2, M = 2e5+4;
int n, m, u, v;

vector<int>adj[N];
bool vis[N];

bool isCyclic(int u, int p){
   vis[u] = true;

   for(int v : adj[u]){

        if (vis[v] && v != p) return true;
        else if (!vis[v]){
            if (isCyclic(v, u)) return true;
        }
   }
   return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    int start;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        start = u; // to handle both o based and 1 based graphs
    }
    puts(isCyclic(start, -1)? "cyclic": "acyclic");
    return 0;
}
