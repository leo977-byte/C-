#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
int main(){
    leona
    int n; cin >> n;
    ll a[n] , p[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        p[i] = sum;
    } 
    ll suffix[n];
    suffix[n - 1] = p[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suffix[i] = min(p[i] , suffix[i + 1]);
    }
    int x = -1;
    for(int i = 0; i < n; i++){
        if(p[i] < 0){
            x = i;
            break;
        }
    }
    if(x == -1){
        cout << "morete chapou: errou conta!" << '\n';
        return 0;
    }
    vector<int> thiago;
    for(int i = 0; i <= x; i++){
        if(suffix[i] - a[i] >= 0){
            if(p[i - 1] - a[i] >= 0){
                thiago.push_back(i + 1);
            }
        }
    }
    if(thiago.empty()){
        cout << "morete chapou: ficou com saldo negativo!" << '\n';
    }else{
        cout << thiago.size() << '\n';
        for(int i = 0; i < thiago.size(); i++){
            cout << thiago[i] << (i == thiago.size() - 1 ? "" : " ") ;
        }
        cout << '\n';
        }
        return 0;
}