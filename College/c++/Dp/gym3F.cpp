#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const int MOD=1e5+5;
const ll N= 2e7+5;
void solve(){
    
        int n , m , k;
        cin >> n >> m >> k;
        int XorSum = 0;
        for(int i = 0;i < n; i++){
            string s; cin >> s;
            int f =  0;
            for (int j = 0; j < m; j++){
                if(s[j] == '1'){ 
                    f = j; 
                    break;
                }
            }
            int l = 0;
            if(f != 0) l = m - f;
            int newl = l % (k + 1);
            XorSum ^= newl;
        }
        if(XorSum !=0){
            cout << "Faris\n";
        }
        else {
            cout << "Hala\n";
        }
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
