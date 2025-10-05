#include<bits/stdc++.h>
using namespace std;



int longestSubstringWithAtmost_K_DistinctCharacters(string &s,int k)
{
    int n=s.size();
    int l=0,r=0,cnt=0;
    vector<int> hash(26,0);
    int maxlen=0;
    while(r<n)
    {
        hash[s[r]-'a']++;
        if(hash[s[r]-'a']==1)
            cnt++;
        while(cnt>k)
        {
            hash[s[l]-'a']--;
            if(hash[s[l]-'a']==0)
                cnt--;
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

int main()
{

}