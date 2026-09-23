#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
using namespace std;
const int N = 105, W = 1e5 + 5;

int wt[N];  
int val[N]; 
int dp[N][W];

void solve() {
    int n, Wi;
    cin >> n >> Wi;

    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= Wi; w++) {
            if (wt[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i] + dp[i - 1][w - wt[i]]);
            } else {
                dp[i][w] = dp[i - 1][w]; 
            }
        }
    }
    cout << dp[n][Wi] << "\n";
}

signed main() {
    leona
    solve();
    return 0;
}