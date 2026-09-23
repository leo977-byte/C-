#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e5+5;
const ll N= 1e3+7;

ll calcDist(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll q,x,y,r;
    cin>>q;
    char op;
    bool flag;
    vector<array<ll,3>>v;
    while(q--) {
        cin>>op>>x>>y>>r;
        flag = true;
        if(op=='A') {
            for (auto [nx,ny,nr] : v) {
                    if (calcDist(nx,ny,x,y)<(nr+r)*(nr+r)){
                        flag = false;
                        break;
                    }
            }
            if (flag) {
                v.push_back({x,y,r});
            }
            flag?cout<<"Ok"<<endl:cout<<"No"<<endl;
        }
        else {
            bool found = false;
            for(int i=0;i<v.size();i++) {
                if(v[i][0] == x && v[i][1] == y && v[i][2] == r ){
                    swap(v[i],v[v.size()-1]);
                    v.pop_back();
                    found = true;
                    break;
                }
            }
            found?cout<<"Ok"<<endl:cout<<"No"<<endl;
        }
    }
}