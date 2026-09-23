#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
const int N = 2e5 + 5;

vector<int> adj[N];
int child[N];
int dfs(int u , int p){
    int res = 0;
    for(auto v : adj[u]){
        if(v == p)continue;
        res+= dfs(v , u) + 1;
    }
    return child[u] = res;
}
void solve(){
    int n; 
    cin  >> n;
    for(int i = 2;i <= n; i++){
        int p; 
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs(1 , 1);
    for(int i = 1; i <= n; i++){
        cout << child[i] << ' ';
    }
}
int main(){
    leona
    solve();
    return 0;
}