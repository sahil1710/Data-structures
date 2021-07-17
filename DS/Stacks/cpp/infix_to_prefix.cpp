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

string infixToPrefix(string s){
    stack<char> st;
    int i;

    string str;

    for (i = s.length()-1; i >=0; i--)
    {
        if(iswalnum(s[i])){
           str += s[i]; 
        }

        else if(s[i]==')'){
            st.push(s[i]);
        }

        else if(s[i]=='('){
            while (st.top()!=')')
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

    reverse(str.begin(),str.end());
    return str;
}

int main(){
    string s = "((A*B)+(C*D))-E";
    cout<<infixToPrefix(s);
}

// output : -+*AB*CDE