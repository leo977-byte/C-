#include <bits/stdc++.h>
using namespace std;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
long long t;//yarab yenfa3
vector<long long> path;

bool dfs(long long c) {
    path.push_back(c);

    if (c == t) {
        return true;
    }
    if (c > t) {
        path.pop_back();
        return false;
    }
    if (dfs(c * 2)) {
        return true;
    }
    if (dfs(c * 10 + 1)) {
        return true;
    }
    path.pop_back();
    return false;
}

void solve() {
    long long root;
    cin >> root >> t;

    if (dfs(root)) {
        cout << "YES" << endl;
        cout << path.size() << endl;
        
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
 
int main(){
    leona
    solve();
    return 0;
}