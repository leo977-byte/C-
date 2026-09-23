#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
const int MAX= 1e6, MOD = 1e9 + 7;
void solve(){
    int n; cin >> n;
    vector<int> p(n + 1);
    vector<int> freq(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        freq[p[i]]++;
    }
    ll leafs = 0, total = 1;

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            leafs++;

            int path = 1;
            int curr = i;
            while (curr != 1 && freq[p[curr]] == 1) {
                path++;
                curr = p[curr];
            }

            total = (total * path) % MOD;
        }
    }

    cout << leafs << " " << total << "\n";

}
int main(){
    leona;
    int t; cin >> t;
    while(t--){ 
        solve();
    }
    return 0;
}