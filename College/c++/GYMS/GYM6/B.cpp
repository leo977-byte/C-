#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
void solve(){
    int n;cin >> n;
    vector<ll> a(n + 1);
    int count = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1) {
            count++;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
    }
    int q ,i; cin >> q;
    ll x;
    while(q--){
        cin >> i >> x;
        
        if (a[i] == 1) count--;
        a[i] = x;
        if (a[i] == 1) count++;

        cout << (count > 0 ? "YES" : "NO") << '\n';
    }

}
int main(){
    leona
    solve();
    
    return 0;
}