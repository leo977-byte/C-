#include <bits/stdc++.h>
using namespace std;
const int N= 1e6+5,MOD=1e9+7,INF=1e18+5;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> res(n);
    map<int, int> mp;
    int x = 1;

    for (int i = 0; i < n; i++) {
        for (int p : primes) {
            if (a[i] % p == 0) {
                if (mp.find(p) == mp.end()) {
                    mp[p] = x++;
                }
                res[i] = mp[p];
                break;
            }
        }
    }
    cout << x - 1 << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i != n - 1) cout << " ";

    }
    cout << endl;
}
int main (){
    leona
    int t; cin >> t;
    while (t--){
        solve();
    }

}