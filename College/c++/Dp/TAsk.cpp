#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int N = 500 ,INF = 1e9;
int dp[N][N];
void solve(){
    int a , b;
    cin >> a >> b;


    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 1;
            
            }
            else{
            dp[i][j] =INF;}
            for (int x = 1; x < j; x++){//vertical
                dp[i][j] = min( dp[i][j] , dp[i][j - x] + dp[i][x]);
            }
            for(int x = 1; x < i; x++){
                dp[i][j] = min( dp[i][j] , dp[i - x][j] + dp[x][j]);
            }
        
        }
    }
    cout << dp[a][b] - 1;
}
int main() {
    leona
    solve();
    return 0;
}