#include <bits/stdc++.h>
using namespace std;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);

const int N = 100005;
vector<int> adj[N];
int vis[N];
int teams[N];

void dfs(int u, bool color) {
    vis[u] = 1;
    if(color) teams[u] = 1;
    else teams[u] = 2;
    for(int v : adj[u]){
        if(vis[v]) continue;
        dfs(v, !color);
    }
}
void solve(){
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]){
            continue;
        }
        dfs(i, true);
    }
    for(int i = 1; i <= n; i++){
        for(auto j : adj[i]){
            if(teams[i] == teams[j]){
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << teams[i] << " ";
    }
}
int main(){
    leona
    solve();
    return 0;
}