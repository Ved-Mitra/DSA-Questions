#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    int n=s.size();
    int cnt=0;
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            st.push(s[i]);
        else
        {
            if(st.empty())
                cnt++;// to calculate extra ')'
            else
                st.pop();
        }
    }
    return cnt+st.size(); // st.size() --> count extra '('
}