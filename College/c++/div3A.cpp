#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int r = 0;

    while (a != b && b != c && a != c) {
        int mx = max(a, max(b, c));
        int mn = min(a, min(b, c));

        if (a == mx) a--;
        else if (b == mx) b--;
        else c--;

        if (a == mn) a++;
        else if (b == mn) b++;
        else c++;

        r++;
    }

    cout << r << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}