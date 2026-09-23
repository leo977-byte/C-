#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 1e6 + 5 ,INF = 1e9;
int dp[N];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
    }
    dp[1] = 0; 

    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            if (digit > 0) {
                dp[i] = min(dp[i], 1 + dp[i - digit]);
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