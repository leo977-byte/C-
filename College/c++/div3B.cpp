#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ilen = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            ilen++;
        }
    }

    int minlen = ilen;

    for (int i = 1; i < n - 1; i++) {
        int cur = ilen;

        if (s[i] == s[i - 1]) {
            cur = ilen;
        } else {
            if (s[i - 1] == s[i + 1]) {
                cur -= 2;
            } 
            else if (s[i] == s[i + 1] || s[i - 1] != s[i + 1]) {
                if (s[i] != s[i + 1]) {
                    cur -= 1;
                }
            }
        }

        minlen = min(minlen, cur);
    }

    cout << minlen << "\n";
}

int main() {
    leona
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}