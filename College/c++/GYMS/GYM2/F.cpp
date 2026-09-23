#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const int N = 4400005, MOD = 1e9 + 7, INF = 1e18 + 1;
int dp[N];

void solve() {
    int n;  cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if(a[i] == a[i-1]) {
            cout << 's\n';
            return;
        }
    }
    dp[0] = 1;
    int sum = 0;
    for (int x : a){
        for(int j = sum; j >= 0; j--){
            if(dp[j]){
                int next = j + x;
                dp[next] += dp[j];
            
                if(dp[next] > 2){
                    cout << 's\n';
                    return;
                }
            }
        }
        sum += x;
    }
    cout << 'n\n';
}

int main() {
    leona 
    solve();
    return 0;
}