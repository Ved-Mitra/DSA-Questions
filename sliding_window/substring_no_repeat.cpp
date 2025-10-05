#include<bits/stdc++.h>
using namespace std;


int LongestSubstringWithoutRepatingCharacters(string &s)
{
    int left = 0, right = 0, maxlen = 0;
    int n=s.size();

    //OPTIMAL
    vector<int> hash1(256,-1);
    while(right<n)
    {
        if(hash1[s[right]]!=-1)
        {
            if(hash1[s[right]]>=left)
            {
                left=hash1[s[right]]+1;
            }
        }
        int len=right-left+1;
        maxlen=max(maxlen,len);
        hash1[s[right]]=right;
        right++;
    }



    //OPTIMAL
    left =right = maxlen = 0;
    vector<int>hash(256,0);
    while (right < n) 
    {
        if(hash[s[right]]==0)
        {
            hash[s[right]]++;
            maxlen=max(maxlen,right-left+1);
            right++;                
        }
        else
        {
            hash[s[left]]--;
            left++;
        }
    }
    return maxlen;
}

int main()
{

}