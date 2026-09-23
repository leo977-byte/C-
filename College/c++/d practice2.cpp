#include <bits/stdc++.h>
using namespace std;
#define int long long
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);

const int N = 1005;
char grid[N][N];
bool vis[N][N];
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y){
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !vis[nx][ny]){
            dfs(nx, ny);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != '#' && !vis[i][j]){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    leona
    solve();
    return 0;
}
