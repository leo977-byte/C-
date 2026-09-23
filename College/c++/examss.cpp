#include <bits/stdc++.h>
using namespace std;
const int N= 1e6+5,MOD=1e9+7,INF=1e18+5;
#define leon ios_base::sync_with_stdio(false); cin.tie(nullptr);
long long binarytodecimal(string s){//O(N)
    long long ans = 0; stack<int> st;//to store the bits in the stack
    int power = 0;//takes the power of 2 for each bit
    for(char c : s){
        st.push(c - '0');//load the stack
    }
    while(!st.empty()){
        int bit = st.top();
        st.pop();
        if(bit == 1){
            ans += pow(2, power);
        }
        power++;
    }
    return ans;
}
bool isbalanced (string s){
    stack<char>st;
    for(char ch : s){
        if (ch =='(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            if(st.empty()){
                return false;
            }
            char top = st.top();
            // Check for mismatch
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')) {
                st.pop(); // It's a match, remove the opening bracket
            } else {
                return false; // Mismatch found
            }
        }
    return st.empty(); // If stack is empty, all brackets are balanced
}

