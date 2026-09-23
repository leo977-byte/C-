#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
using namespace std;
const ll INF = 1e18;
int main(){
    leona
    string s; getline(cin , s);
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')){
        s.pop_back();
    }
    if(!s.empty() && s.back() == '?'){
        cout << "7\n";
        return 0;
    }
    stringstream ss(s);
    string c;
    bool sussu = false;
    while(ss >> c){
        string x = "";
        for(char i : c){
            if(isalpha(i)){
                x += i;
            }
        }
        if(x == "Sussu"){
            sussu =true;
            break;
        }
    }
    if(sussu){
        cout << "AI SUSSU!" << '\n';
    }
    else{
        cout << "O cara é bom!" << '\n';
    }
}