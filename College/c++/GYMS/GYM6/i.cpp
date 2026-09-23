#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string res = "";
    bool valid = true; int i = 0;
    while(i < n){
        if(s[i] != 'a' || i + 1 >= n || s[i + 1] != 'b'){
            valid = false;
            break;
        }
    if(i + 2 < n && s[i + 2] == 'a'){
        if(i + 3 < n && s[i + 3] == 'b'){
            res += '0';
            i += 2;
        }else{
            res += '1';
            i += 3;
        }
    }else{
            res += '0';
            i += 2;
        }
    }
    if(valid && i == n) {
        cout << res << '\n';
    } else {
        cout << ":(\n";
    }
}
int main(){
    leona
    solve();
    
    return 0;
}