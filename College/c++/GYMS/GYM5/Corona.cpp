#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
int main(){
    leona
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    ll best = -1;
    int max = -1;
    for(int i = 0; i < n; i++){
        if(i == n - 1 || a[i] != a[i + 1]){
            int count = i + 1;
            if(count % 3 == 0){
                if(count > max){
                    max = count;
                    best = a[i];
                }   
            }
        }
    }  
    cout << best << '\n';
    return 0;
}
