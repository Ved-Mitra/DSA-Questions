#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s,int start,int end)
{
    while(start<=end)
    {
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}
void palindromePartioning(vector<vector<string>> &ans,string &s,vector<string> &arr,int index)
{
    if(index==s.size())
    {
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        if(isPalindrome(s,index,i))
        {
            arr.push_back(s.substr(index,i-index+1));
            palindromePartioning(ans,s,arr,i+1);
            arr.pop_back();
        }
    }
}

int main()
{

}