#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
int dp[1005][1005];
void solve(){
    leona
    string a , b;
    cin >> a >> b;
    int n = a.size() , m = b.size();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << '\n';
}