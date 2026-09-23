#include <bits/stdc++.h>
using namespace std;
const long long INF = 200005;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
void solve(){
    int n; cin >> n;
    vector<int> c(n);
    vector<int> pos(INF , -1);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        pos[c[i]] = i;
    }
    int j = 0 , cur = 0;
    while(cur < n - 1){
        int color = c[cur];
        int back = pos[color];

        if(back > cur) {
            cur = back;
        }else{ 
            cur++;
        }
        j++;
    }
    cout << j << "\n";
}
int main(){
    leona 
    int t; cin >> t; while (t--){
        solve();

    }
}
