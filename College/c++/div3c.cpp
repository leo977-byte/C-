#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<int> pos_a, pos_b;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') pos_a.push_back(i);
        if (b[i] == '1') pos_b.push_back(i);
    }

    if (pos_a.size() != pos_b.size()) {
        cout << -1 << "\n";
        return;
    }

    ll total_diff = 0;
    ll ans = 0;

    for (size_t i = 0; i < pos_a.size(); i++) {
        ll diff = abs(pos_a[i] - pos_b[i]);
        ans += diff;
        total_diff += (pos_a[i] - pos_b[i]);
    }

    if (total_diff % 2 != 0) {
        cout << -1 << "\n";
    } else {
        cout << ans / 2 << "\n";
    }
}

int main() {
    leona;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}