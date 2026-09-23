#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const int N = 305, MOD = 1e9 + 7, INF = 1e18 + 1;
int main() {
    leona 
    ll n; cin >> n;
    vector<string> a = {"Sheldon" , "Leonard", "Penny", "Rajesh", "Howard"};
    ll size = 1;
    while(n > 5 *size){
        n -= 5 * size;
        size *= 2;
    }
    int x = (n - 1) / size;
    cout << a[x] << endl;
}
