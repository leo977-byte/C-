#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 5005;
vector<pair<int, int>> adj[N];
bool vis[N];
int n, q;
int cur; 
int visited_count;
void dfs(int u) {
    vis[u] = true;
    for (auto edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;
        
        if (!vis[v] && weight >= cur) {
            visited_count++;
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        
        for (int j = 1; j <= n; j++) {
            vis[j] = false;
        }
        cur = k;
        visited_count = 0;

        dfs(v);

        cout << visited_count << "\n";
    }
}

int main() {
    leona
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    solve();
    return 0;
}