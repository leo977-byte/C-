#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e5+5;
const ll N= 1e5;
int p[N];
int l[N];

void solve() {
    int n, m, L; cin >> n >> m >> L;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }
    int mx=-1e9;
    sort(p, p+n);
    for (int i = 1; i < n; i++) {
        mx = max(mx, abs((p[i]-p[i-1]+1)/2));
    }
    mx = max(mx, abs(p[n-1]-L));
    mx = max(mx, p[0]);
    sort(l, l+m);
    auto ptr = lower_bound(l, l+m, mx);

    if (ptr == l+m) {
        cout << -1;
        return;
    }
    cout << *ptr;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    // cin >> t;
    while (t--) {
        solve();
    }
}