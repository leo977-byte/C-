#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 305, MOD = 1e9 + 7, INF = 1e18 + 1;
double dp[N][N][N];

void solve(){
    int n; cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        if (val == 1) c1++;
        else if (val == 2) c2++;
        else if (val == 3) c3++;
    }

    dp[0][0][0] = 0.0;
    for(int k = 0; k <= n; k++){
        for(int j = 0; j <= n; j++){
            for(int i = 0; i <= n; i++){
                if(i + j + k == 0) continue;
                if(i + j + k > n) continue;

                double total = i + j + k;
                double res = n;
                if (i > 0) res += i * dp[i - 1][j][k];
                if (j > 0) res += j * dp[i + 1][j - 1][k];
                if (k > 0) res += k * dp[i][j + 1][k - 1];
                dp[i][j][k] = res /total;
                
            }
        }
    }
    cout << setprecision(10) << dp[c1][c2][c3] << "\n";

}
int main() {
    leona
    solve();
    return 0;
}