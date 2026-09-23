#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 305, MOD = 1e9 + 7, INF = 1e18 + 1;
double dp[N][N][N];
bool V[N][N][N];
int n;

double rec(int c1, int c2, int c3) {
    if (c1 + c2 + c3 == 0) return 0.0;
    
    if (V[c1][c2][c3]) return dp[c1][c2][c3];
    
    double total = c1 + c2 + c3;
    double res = n; 
    
    if (c1 > 0) res += c1 * rec(c1 - 1, c2, c3);
    if (c2 > 0) res += c2 * rec(c1 + 1, c2 - 1, c3);
    if (c3 > 0) res += c3 * rec(c1, c2 + 1, c3 - 1);
    
    res /= total;
    
    V[c1][c2][c3] = true;
    return dp[c1][c2][c3] = res;
}

void solve() {
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val == 1) c1++;
        else if (val == 2) c2++;
        else if (val == 3) c3++;
    }
    
    cout << setprecision(10) << rec(c1, c2, c3) << "\n";
}

int main() {
    leona
    solve();
    return 0;
}