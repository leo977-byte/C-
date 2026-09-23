#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int X = 1e6 + 5 , MOD = 1e9 + 7 , N = 105;
int dp[X]; 

void solve() {
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 1; 

    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++) {
            if (i - coins[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    cout << dp[x] << "\n";
}

int main() {
    leona
    solve();
    return 0;
}