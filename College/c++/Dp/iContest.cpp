#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 2e5 + 5 , INF = 1e9;
int c[N];
int dp[N];
int par[N];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
        par[c[i]] = -1; 
    }

    dp[1] = 0; 
    par[c[1]] = 1; 

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);

        if (par[c[i]] != -1) { 
            dp[i] = min(dp[i], dp[par[c[i]]] + 1);
        }

        par[c[i]] = i;
    }

    cout << dp[n] << "\n";
}

int main() {
    leona
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}