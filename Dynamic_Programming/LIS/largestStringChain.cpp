#include <bits/stdc++.h>
using namespace std;

bool isChain(string &s1,string &s2)
{
    if(s2.size()!=s1.size()+1)
        return false;
    int i=0,j=0,cnt=0;
    while(i<s1.size() && j<s2.size())
    {
        if(s1[i]!=s2[j])
        {
            j++;
            cnt++;
        }
        else
        {
            i++;
            j++;
        }
        if(cnt>1)
            return false;
    }
    return cnt<=1;
}
bool comp(string &s1,string &s2)
{
    return s1.size()<s2.size();
}
int longestStrChain(vector<string> &words)
{
    int n=words.size();
    sort(words.begin(),words.end(),comp);
    vector<int> dp(n,1);
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(isChain(words[prev],words[i]))
            {
                dp[i]=max(dp[i],1+dp[prev]);
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
}











int main()
{

}