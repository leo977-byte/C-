#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int MOD = 1e9 + 7 , N = 1e6 + 5 ,INF = 1e9;
//happy birthday
int dp[N];

void solve() {
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;

    if (sum % 2 != 0) {
        cout << 0 << "\n";
        return;
    }

    int t = sum / 2;

    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = t; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]);
            dp[j] %= MOD;
        }
    }

    cout << dp[t] << "\n";
}

int main() {
    leona
    solve();
    return 0;
}