#include <bits/stdc++.h>
using namespace std;

string Reverse(string str1, int n){
    stack<char> S;
    int i;
    for(i=0;i<n;i++){
        S.push(str1[i]);
    }
    str1 = "";

    for(i=0;i<n;i++){
        str1 = str1 + S.top();
        S.pop();
    }
    return str1;
}

int main(){
    string str1 = "Hello";
    cout<<Reverse(str1, str1.length());
}

// output : olleH
