#include <bits/stdc++.h>
using namespace std;

string generate(string &s)
{
    int n=s.size();
    string str="";
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(i<n && s[i]==s[i-1])
            cnt++;
        else
        {
            str+=to_string(cnt);
            str+=s[i-1];
            cnt=1;
        }
    }
    return str;
}
string countAndSay(int n) {
    string s="1";
    for(int i=1;i<n;i++)
    {
        s=generate(s);
        // cout << s << '\n';
    }
    return s;
}