#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7;
int dp[N];

void solve() {
    int n;
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";
}

int main() {
    leona
    solve();
    return 0;
}