#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 1e5 + 7 ,M = 105, MOD = 1e9 + 7;
int x[N];
int dp[N][M];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    if (x[1] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[1][j] = 1;
        }
    } else {
        dp[1][x[1]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int v = j - 1; v <= j + 1; v++) {
                    if (v >= 1 && v <= m) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][v]) % MOD;
                    }
                }
            }
        } else {
            int j = x[i];
            for (int v = j - 1; v <= j + 1; v++) {
                if (v >= 1 && v <= m) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][v]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    if (x[n] == 0) {
        for (int j = 1; j <= m; j++) {
            ans += dp[n][j];
            ans %= MOD;
        }
    } else {
        ans = dp[n][x[n]];
    }

    cout << ans << "\n";
}

int main() {
    leona
    solve();
    return 0;
}