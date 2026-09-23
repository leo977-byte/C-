#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const ll INF = 1e18;
int main(){
    leona
    int n;
    cin >> n;
    ll sum = 0 , odd = INF;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        sum += a;
        if(a % 2 != 0){
            odd = min(odd , a);
        }
    }
    if(sum % 2 != 0){
        sum -= odd;
    }
    cout << sum << '\n';
    return 0;
}