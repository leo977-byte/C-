#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 1005 , X = 100005;
int price[N] , pages[N];  
int dp[N][X]; 

void solve() {
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
     cin >> price[i];
    for (int i = 1; i <= n; i++)
     cin >> pages[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (price[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], pages[i] + dp[i - 1][j - price[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][x] << "\n";
}

int main() {
    leona
    solve();
    return 0;
}