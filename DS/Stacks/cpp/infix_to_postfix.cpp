#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '*' || c == '/') 
    return 1;

    else if(c == '+' || c == '-') 
    return 0;

    else
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;

    string str;

    for (int i = 0; i < s.length(); i++)
    {
        if(iswalnum(s[i])){
           str += s[i]; 
        }

        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){
            while (st.top()!='(')
            {
                str += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                str += st.top();
                st.pop(); 
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        str += st.top();
        st.pop();
    }
    
    return str;
}

int main(){
    string s = "((A+B)*C-D)*E";
    cout<<infixToPostfix(s);
}

// output : AB+C*D-E*