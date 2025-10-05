#include<bits/stdc++.h>
using namespace std;


/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.*/
string minWindowSubstring(string &s,string t)
{
    int n=s.size();
    int m=t.size();
    if(m>n)
        return "";
    
    //OPTIMAL-ME
    //TC-O(m+n)
    //SC-O(1)
    vector<int> hash_s(256,0),hasht(256,0);
    for(int i=0;i<m;i++)
        hasht[t[i]]++;
    int minlen=INT_MAX,l=0,r=0,start=-1,end=-1;
    while(r<n)
    {
        hash_s[s[r]]++;
        if(hash_s[s[r]]>=hasht[s[r]])
        {
            int flag=1;
            for(int i=65;i<91;i++)
                if(hash_s[i]<hasht[i])
                {
                    flag=0;
                    break;
                }
            if(flag)
            {
                for(int i=97;i<123;i++)
                    if(hash_s[i]<hasht[i])
                    {
                        flag=0;
                        break;
                    }
                if(flag)
                {
                    while(hash_s[s[l]]>hasht[s[l]])
                    {
                        hash_s[s[l]]--;
                        l++;
                    }
                    if(minlen>(r-l+1))
                    {
                        minlen=r-l+1;
                        start=l;
                        end=r;
                    }
                }
            }
        }
        r++;
    }
    string str="";
    if(start!=-1 && end!=-1)
    {
        for(int i=start;i<=end;i++)
            str+=s[i];
    }
    return str;


    //OPTIMAL-STRIVER
    //TC-O(m+n)
    //SC-O(1)
    vector<int> hash(256,0);
    for(int i=0;i<m;i++)
        hash[t[i]]++;
    l=r=0;
    minlen=INT_MAX;
    int cnt=0,SIndex=-1;
    while(r<n)
    {
        if(hash[s[r]]>0)
            cnt++;
        hash[s[r]]--;
        while(cnt==m)
        {
            if(r-l+1<minlen)
            {
                minlen=r-l+1;
                SIndex=l;
            }
            hash[s[l]]--;
            if(hash[s[l]]>0)
                cnt--;
            l++;
        }
        r++;
    }
    return SIndex==-1?"":s.substr(SIndex,minlen);
}

int main()
{

}