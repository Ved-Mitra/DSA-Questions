#include <bits/stdc++.h>
using namespace std;

//done by FORWARD PARTITION
//start from the front and go on checking till a palindrome is encountered then put a prtition there i.e.example : ababbba 
// now here i travel till aba|bbba while doing forward pass i found a partition where left is palindrom now i jus pass right partition in recursion to check same forward pass in right partition
//      aba|bbba
//cost = 1 + cost(bbba)

/*
WRITING A RECURRENCE
1. Express everything in terms of Index
2. Express all possibilities
3. Take the minimum of all possibilities
4. Write the base case
*/

bool isPalindrome(string &s)
{
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-1-i])
            return false;
    return true;
}

int recursiveHelper(string &s,vector<int>&dp ,int i)
{
    //TC-O(N^2)
    //SC-O(N)
    if(i==s.size())
        return 0;

    if(dp[i]!=-1)
        return dp[i];
    
    string temp="";
    int cost=INT_MAX;
    for(int j=i;j<s.size();j++)
    {
        temp+=s[j];
        if(isPalindrome(temp))
            cost=min(cost,1+recursiveHelper(s,dp,j+1));
    }
    return dp[i]=cost;
}

int minCut_Memoization(string s)
{
    int n=s.size();
    vector<int> dp(n,-1);
    return recursiveHelper(s,dp,0)-1;// -1 to remove the partition made at the end 
}

int minCut_Tabulation(string s)
{
    int n=s.size();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        string temp="";
        int cost=INT_MAX;
        for(int j=i;j<n;j++)
        {
            temp+=s[j];
            if(isPalindrome(temp))
                cost=min(cost,1+dp[j+1]);
        }
        dp[i]=cost;
    }

    return dp[0];
}

int main()
{

}