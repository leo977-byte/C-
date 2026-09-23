#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAX = 1e6;
int cnt[MAX + 1];        
int f[MAX + 1];     
bool on[MAX + 1];             
vector<int> divi[MAX + 1];

void find_divs() {
    for (int i = 1; i <= MAX; i++) {
        for (int j = i; j <= MAX; j += i) {
            divi[j].push_back(i);
        }
    }
}

void solve() {
    int n; 
    cin >> n;
    int ans = 0;

    while (n--) {
        int x; 
        cin >> x;

        if (!on[x]) { 
            on[x] = true;
            for (int d : divi[x]) {
                if (d == 1) continue;

                f[cnt[d]]--;
                cnt[d]++;
                f[cnt[d]]++;

                ans = max(ans, cnt[d]);
            }
        } else { 
            on[x] = false;
            for (int d : divi[x]) {
                if (d == 1) continue;

                f[cnt[d]]--;
                cnt[d]--;
                f[cnt[d]]++;
            }
            while (ans > 0 && f[ans] == 0) {
                ans--;
            }
        }

        cout << ans << '\n';
    }
}

int main() {
    leona
    find_divs();
    solve();
    return 0;
}