#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7, INF = 1e10 + 1;
int a[105];
int dp[N];
int n, k;
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= a[j]) {
                if (dp[i - a[j]] == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }

    if (dp[k] == 1) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

int main() {
    leona
    solve();
    return 0;
}