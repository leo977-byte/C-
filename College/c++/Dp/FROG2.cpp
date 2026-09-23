#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7, INF = 1e9;

int dp[N];
int h[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        dp[i] = INF;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        if (i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }
    cout << dp[n - 1];
}

signed main() {
    leona
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}