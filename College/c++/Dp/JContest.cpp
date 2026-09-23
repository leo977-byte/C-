#include <bits/stdc++.h>
using namespace std;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
int main(){
    leona
    int t , num;
    cin >> t; 
    while (t--){
        int n; cin >> n;
        long long MOD = 1e9 + 7;
        long long ans = 1;
        for (int i = 0; i < n; i++){
             cin >> num;
             ans = (ans * (num + 1)) % MOD;
        }
        ans -= 1;
        if (ans < 0){
            ans += MOD;
        }
        cout << ans << "\n";

    }
}