#include<bits/stdc++.h>
using namespace std;
#define leon ios_base::sync_with_stdio(false); cin.tie(nullptr);

void bracketdelimitercheck(string exp){
    stack<char> s;
    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            s.push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(s.empty()) {
                cout << "the expression is not balanced" << endl;
                return;
            }
            char top = s.top();
            s.pop();
            if((exp[i] == ')' && top != '(') || (exp[i] == '}' && top != '{') || (exp[i] == ']' && top != '[')){
                cout << "the expression is not balanced" << endl;
                return;
            }
        }
    }
    if(s.empty()) cout << "the expression is balanced" << endl;
    else cout << "the expression is not balanced" << endl;
}


int priority(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}
int to_postfix (string exp){
    stack<char> s;
    string output = "";
    for(int i  = 0; i < exp.size(); i++){
        if(exp[i] == ' ') continue;
        if(isdigit(exp[i]) || isalpha(exp[i])){
            output+=exp[i];
        }
        else if(exp[i] == '('){
            s.push('(');
        }
        else if(exp[i] == ')'){
            while(s.top() != '('){
                output += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while(priority(exp[i]) <= priority(s.top())){
                output += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(!s.empty()){
        output += s.top();
        s.pop();
    }
    return 0;
}
float mathoperations(float op1, float op2, char op){
    if(op == '+') return ;
    else if(op == '-') return op1 - op2;
    else if(op == '*') return op1 * op2;
    else if(op == '/') return op1 / op2;
    else return 0;
}
float evaluate_postfix(string postfix ){
    stack <float> st;
    for(int i = 0 ; i < postfix.size(); i++){
        if(isdigit(postfix[i]) - '0'){
            st.push(postfix[i]);
        }
        else{
            float op2 = st.top();
            st.pop();
            float op1 = st.top();
            st.pop();
            float result = mathoperations( op2 , op1, postfix[i]);
            st.push(result);

        }
    }

}
int main (){
    leon
    string exp;
    cin >> exp;
    to_postfix(exp);
     return 0;
}