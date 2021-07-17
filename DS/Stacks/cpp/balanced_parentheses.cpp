#include <bits/stdc++.h>
using namespace std;
// balanced parentheses = [()()], {[()]}
// not balanced parentheses = )( , [(]), ([){}]

string parentheses(string str1, int n){
    stack<char> S;
    int i;
    for(i=0;i<n;i++){
        if(str1[i]=='(' || str1[i]=='{' || str1[i]=='['){
            S.push(str1[i]);
        }

        else if(str1[i]==')' || str1[i]=='}' || str1[i]==']'){
            if(S.empty()){
                return "parentheses are not balanced";
            }
            else if(str1[i]==')'&& S.top()!='('){
                return "parentheses are not balanced";
            }
            else if(str1[i]=='{'&& S.top()!='{'){
                return "parentheses are not balanced";
            }
            else if(str1[i]=='['&& S.top()!='['){
                return "parentheses are not balanced";
            }
            else S.pop();
        }
    }
    
    return S.empty() ? "parentheses are balanced":"parentheses are not balanced";
}


int main(){
    string str1= "[{()()}]";
    cout<<parentheses(str1, str1.length());
}

// output: parentheses are balanced