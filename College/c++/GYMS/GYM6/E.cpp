#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const int MAX = 1e6;
int cnt[MAX + 1];
bool on[MAX + 1];
vector<int> divisors[MAX + 1];

void find_all_divisors(){// nlogn
    for(int i=1;i<MAX;i++){
        for(int j=i;j<MAX;j+=i){
            divisors[j].push_back(i);
        }
    }
}
void solve(){
    int n; cin >> n;
    while (n--){
        int x; cin >> x;
        if(!on[x]){
            on[x] = true;
            for(int d : divisors[x]){
                cnt[d]++;
            }
        }
        else{
            on[x] = false;
            for(int d : divisors[x]){
                cnt[d]--;
            }
        }
        int ans = 0;
        for(int k = 2; k <= MAX; k++){
            ans = max(ans , cnt[k]);
        }
        cout << ans << '\n';
    }
}
int main(){
    leona
    find_all_divisors();
    
    return 0;
}