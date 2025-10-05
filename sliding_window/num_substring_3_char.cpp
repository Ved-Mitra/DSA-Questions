#include<bits/stdc++.h>
using namespace std;

/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.*/
int numberOfSubstringsContainingAllThreeCharacters(string &s)
{
    int n=s.size();

    //BRUTE
    //TC-O(N^2)
    //SC-O(1)
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        vector<int> hash(3,0);
        for(int j=i;j<n;j++)
        {
            hash[s[j]-'a']++;
            if(hash[0] && hash[2] && hash[3])
                cnt++;
        }
    }
    return cnt;


    //BETTER
    cnt=0;
    for(int i=0;i<n;i++)
    {
        vector<int> hash(3,0);
        for(int j=i;j<n;j++)
        {
            hash[s[j]-'a']++;
            if(hash[0] && hash[2] && hash[1])
            {
                cnt+=(n-j);
                break;
            }
        }
    }
    return cnt;



    //OPTIMAL
    cnt=0;
    int l=0,r=0;
    vector<int> hash(3,-1);
    while(r<n)
    {
        hash[s[r]-'a']=r;
        if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1)
        {
            l=min(hash[0],min(hash[1],hash[2]));
            cnt+=(l+1);
        }
        r++;
    }
    return cnt;
    
}

int main()
{

}