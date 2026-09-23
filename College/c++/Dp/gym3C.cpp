#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
int main(){
    leona
    int n; cin >> n;
    int count3 = 0 , count5 = 0 ,count15 = 0;
    for(int i = 0 ; i < n ; ++i){
        int val; cin >> val;
        if(val % 15 == 0) count15++;
        else if(val % 3 == 0) count3++;
        else if(val % 5 == 0) count5++;
        
    }
    int res = count15 + min(count3 , count5);
    cout << res << "\n";

}