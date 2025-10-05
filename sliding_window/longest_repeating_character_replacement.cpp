#include<bits/stdc++.h>
using namespace std;

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/
int longestRepeatingCharacterReplacement(string &s,int k)
{
    int n=s.size();
    int maxlen=0;

    //BRUTE
    for(int i=0;i<n;i++)
    {
        vector<int> hash(26,0);
        int max_f=0;
        for(int j=i;j<n;j++)
        {
            hash[s[j]-'A']++;
            max_f=max(max_f,hash[s[i]-'A']);
            int changes=(j-i+1)-max_f;
            if(changes<=k)
                maxlen=max(maxlen,j-i+1);
            else
                break;
        }
    }
    return maxlen;



    //BETTER
    //TC-O(N)+O(N)*26
    int l=0,r=0,max_f=0;
    maxlen=0;
    vector<int> hash(26,0);
    while(r<n)
    {
        hash[s[r]-'A']++;
        max_f=max(max_f,hash[s[r]-'A']);
        while((r-l+1)-max_f>k)
        {
            hash[s[l]-'A']--;
            max_f=0;
            for(int i=0;i<26;i++)
                max_f=max(max_f,hash[i]);
            l++;
        }
        if((r-l+1)-max_f<=k)
            maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;



    //OPTIMAL
    //TC-O(N)
    l=r=max_f=maxlen=0;
    while(r<n)
    {
        hash[s[r]-'A']++;
        max_f=max(max_f,hash[s[r]-'A']);
        if((r-l+1)-max_f>k)
        {
            hash[s[l]-'A']--;
            max_f=0;
            l++;
        }
        if((r-l+1)-max_f<=k)
            maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

int main()
{

}