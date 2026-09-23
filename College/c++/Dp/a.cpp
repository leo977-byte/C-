#include <bits/stdc++.h>
using namespace std;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long 
const int N = 200005;

vector<int> adj[N];
ll leaves[N];

void dfs(int u, int p) {
    bool isleaf = true;
    leaves[u] = 0;
    
    for (int v : adj[u]) {
        if (v != p) {
            isleaf = false;
            dfs(v, u);
            leaves[u] += leaves[v];
        }
    }
    
    if (isleaf) {
        leaves[u] = 1;
    }
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    int q , x, y;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        cout << leaves[x] * leaves[y] << "\n";
    }
}

int main() {
    leona
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}