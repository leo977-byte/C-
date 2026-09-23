#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int X = 1e6 + 5 , N = 105 ,INF = 1e9;
//Coin Minizzz :0
int coins[N];
int dp[X];

void solve() {
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for (int i = 0; i <= x; i++) {
        dp[i] = INF;
    }
    
    dp[0] = 0;  

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    if (dp[x] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[x] << "\n";
    }
}

int main() {
    leona
    solve();
    return 0;
}