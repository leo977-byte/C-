#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 105 , Max = 100005;
int x[N];
bool dp[Max];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int pos = x[i];
        for (int j = Max; j >= pos; j--) {
            if (dp[j - x[i]]) {
                dp[j] = 1;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i < Max; i++) {
        if (dp[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    leona
    solve();
    return 0;
}