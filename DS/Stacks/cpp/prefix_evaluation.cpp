#include <bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s){
    stack<int> st;
    int a,b;

    for(int i=s.length()-1; i>=0;i--){
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
                st.push(a*b);
                break;
            
            case '/':
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a/b);
                break;
            
            case '+':
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a+b);
                break;

            case '-':
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a-b);
                break;

            default:
                break;
            }
        }
    }
    
    return st.top();
}

int main(){
    string s = "-+*23*549";
    cout<<prefixEvaluation(s);
}

// output : 17