#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e5+5;
const ll N= 1e7+5;

bool dp[N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t , n , m , k;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        unsigned ll  a[n+1];
        memset(dp,0,sizeof(dp));
    
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        int Maxk = min(k , 20);
        for (int i=1;i<=Maxk ;i++) {
            for (int j=1;j<=n;j++) {
                if (a[j]!=0 && a[j]<N && !dp[a[j]>>i] ) {
                    if(a[j]<N) dp[a[j]]=true;
                    a[j]=a[j]>>i;
                }
            }
        }
        if(k < N){
            cout<<(dp[k]?"Faris\n":"Hala\n");
        }
        else{
            cout<<"Hala\n";
        }
    }
}