#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
vector<int> primes(int n){
    vector<int> res;
    for(int i = 2 ; i * i <= n ; i++){
        if(n % i == 0){
            res.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) res.push_back(n);
    return res;
}
void solve(){
    int y , k;
    cin >> y >> k;
    int x = 1;
    vector<int> p = primes(y);
    while(k > 0){
        int g = std::gcd(x , y);
        int px = x / g;
        int py = y / g;
        if(py == 1){
            x += k * y;
            break;
        }
        
        int min = k;
        for(int i : p){
            int steps = i - (px % i);
            min = std::min(min, steps);
        }
        x += min * g;
        k -= min;
    }
    cout << x << '\n';
}
signed main(){
    leona
    solve();
    return 0;
}