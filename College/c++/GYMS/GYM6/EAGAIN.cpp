#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int MAXV = 1e6+ 5, N= 1e4 + 6;

bool on[MAXV];
int cnt[MAXV];
int freq[N];

int main(){

    int n;
    cin >> n;
    freq[0] = MAXV;
    int mx = 0;

    while (n--) {
        int x;
        cin >> x;

        int c = on[x] ? -1 : 1;
        on[x] = !on[x];

        vector<int> divs;

        for (int i = 1; 1LL * i * i <= x; i++) {
            if (x % i == 0) {
                if (i > 1) divs.push_back(i);
                int j = x / i;
                if (j != i && j > 1) divs.push_back(j);
            }
        }

        for (int d : divs) {
            freq[cnt[d]]--;
            cnt[d] += c;
            freq[cnt[d]]++;
            if (cnt[d] > mx) mx = cnt[d];
        }

        while (mx > 0 && freq[mx] == 0)
            mx--;

        cout << mx << '\n';
    }

    return 0;
}