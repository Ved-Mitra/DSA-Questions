#include<bits/stdc++.h>
using namespace std;


int longestValidParenthesis(string &s)
{
    stack<char> st;
    int n=s.size();
    int maxx=0,cnt=0,maxCnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
            cnt++;
            maxCnt++;
        }
        else
        {
            if(!st.empty())
            {
                cnt--;
                st.pop();
            }
            else
            {
                return maxx;
            }
        }

        if(cnt==0)
            maxx=maxCnt*2;
    }
    return maxx;
}


int main()
{
    string s;
    cin >>s;
    cout << longestValidParenthesis(s) << endl;
}