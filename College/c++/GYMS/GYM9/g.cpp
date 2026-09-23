#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
const int MAX= 1e6;
void solve(){
    ll n , k , x; cin >> n >> k >> x;   
    vector<ll> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    ll ops = 0;
    for(int i = 0; i < k ; i++){
        vector<ll> v;
        for(int j = i; j < n; j+=k){
            v.push_back(a[j]);
        }
        sort(v.begin() , v.end());
        ll med = v[v.size()/2];
        for(ll val : v){
            ops += abs(val - med);
        }
    }
    cout << ops * x << '\n';
}
int main(){
    leona;
    int t; cin >> t;
    while(t--){ 
        solve();
    }
}