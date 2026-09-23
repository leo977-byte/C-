#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const int N = 1e3, MOD = 1e9 + 7, INF = 1e9 + 1;
void solve(){
    int n , m; cin >> n >> m;
    vector<vector<int>> a(n , vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
        sort(a[i].begin() , a[i].end());
    }
    long long maxBeauty = 0;
    for(int i = 1; i < n; i++){
        int prev = 0;
        int cur = 0;
        while(prev < m && cur < m){
            if(a[i-1][prev] == a[i][cur]){
                maxBeauty++;
                prev++;
                cur++;
            }
            else if(a[i-1][prev] < a[i][cur]) {
                prev++;
            }
            else{
                cur++;
            }
        }
    }
    cout << maxBeauty << '\n';
}
int main() {
    leona;
    int t;
    cin >> t;
    while(t--){ 
        solve();
    }
    return 0;
}