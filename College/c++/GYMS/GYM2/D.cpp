#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const int N = 305, MOD = 1e9 + 7, INF = 1e18 + 1;
int main() {
    leona 
    string s;
    cin >> s;
    ll total = 0 , count = 0;
    for(int i =  s.length() - 1; i >= 0; i--){
        if(s[i] == 'b'){
            count = (count + 1) % MOD;
        }
        else if(s[i] == 'a'){
            total = (total + count) % MOD;
            count = (count * 2) % MOD;
        }
    }
    cout << total << endl;
}