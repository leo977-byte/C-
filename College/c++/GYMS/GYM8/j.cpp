#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
const int MAX= 1e6;
bool on[MAX];
int cnt [MAX];
int freq[MAX];
int gcd(int a, int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
signed main(){
    leona
    int n , s;
    cin >> n >> s;
    int cnt = gcd(n , s);
    int ans = n / cnt;
    cout << ans << '\n';
}
