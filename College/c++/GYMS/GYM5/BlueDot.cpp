#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
int main(){
    leona
    int n , x , count = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 1){
            count++;
        }
    }
    if(count == n) cout << n << '\n';
    else cout << count + 1 << '\n';
}