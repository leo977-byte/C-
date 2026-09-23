#include <bits/stdc++.h>
using namespace std;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);

const int N = 100005;
vector<int> adj[N];
bool vis[N];
int n, m;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    if (!(cin >> n >> m)) return;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> v;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            v.push_back(i);
            dfs(i);
        }
    }

    int k = v.size() - 1;
    cout << k <<endl;

    for (int i = 0; i < k; i++) {
        cout << v[i] << " " << v[i + 1];
        if (i != k - 1) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    leona
    solve();
    return 0;
}