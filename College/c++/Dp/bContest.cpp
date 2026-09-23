#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
signed main(){
    int t , n , m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int arr[n];
        for (int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        for (int i = 1; i < n; i++){
            if(arr[i] == -1 && arr[i - 1] != -1){
                arr[i] = (arr[i - 1] + 1) % m;
            }
        }
        for (int i = n - 2; i >= 0; i--){
            if(arr[i] == -1 && arr[i + 1] != -1){
                arr[i] = (arr[i + 1] - 1 + m) % m;
            }
        }
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}