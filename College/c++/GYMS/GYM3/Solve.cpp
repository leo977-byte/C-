#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const int N = 305, MOD = 1e9 + 7, INF = 1e9 + 1;
void solve(){
    int n , m; cin >> n >> m;
    string s , c , p; cin >> s >> c >> p;
    vector<int> cost(26 , INF);
    for(int i = 0; i < n; i++){
        int x = s[i] - 'a';
        int cost_val = c[i] - '0';
        cost[x] = min(cost[x] , cost_val);
    }
    int total = 0;
    for(int i = 0; i < m; i++){
        int x = p[i] - 'a';
        if(cost[x] == INF){
            cout << -1 << endl;
            return;
        }
        total += cost[x];
    }
    cout << total << endl;
}

int main() {
    leona;
    int t;
    cin >> t;
    while(t--){ 
        solve();
    }
    return 0;
}