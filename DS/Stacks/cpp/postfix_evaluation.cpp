#include <bits/stdc++.h>
using namespace std;

int postfixEvaluation(string s){
    stack<int> st;
    int a,b;

    for(int i=0; i<s.length();i++){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }

        else{
            switch (s[i])
            {
            case '*':
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b*a);
                break;
            
            case '/':
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b/a);
                break;
            
            case '+':
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b+a);
                break;

            case '-':
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b-a);
                break;

            default:
                break;
            }
        }
    }
    
    return st.top();
}

int main(){
    string s = "23*54*+9-";
    cout<<postfixEvaluation(s);
}

// output: 17