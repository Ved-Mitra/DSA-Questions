#include<bits/stdc++.h>
using namespace std;

/*Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".*/


bool recursiveWay(string &s,int index,int cnt)
{
    if(cnt<0)
        return false;
    if(index==s.size())
        return cnt==0;
    if(s[index]=='(')
        return recursiveWay(s,index+1,cnt+1);
    if(s[index]==')')
        return recursiveWay(s,index+1,cnt-1);
    return recursiveWay(s,index+1,cnt+1) || recursiveWay(s,index+1,cnt-1) || recursiveWay(s,index+1,cnt);
}

bool checkValidString(string &s)
{
    //BRUTE
    //TC-O(3^n)
    //SC-O(n)
    recursiveWay(s,0,0);

    //BETTER
    //TC-O(n^2)
    //SC-O(n^2)
    //USE DP

    //OPTIMAL
    //TC-O(n)
    //SC-O(1)
    int n=s.size();
    int min=0,max=0;
    if(s[0]==')')
        return false;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            max++;
            min++;
        }
        else if(s[i]==')')
        {
            max--;
            min--;
        }
        else
        {
            min--;
            max++;
        }
        if(min<0)
            min=0;
        if(max<0)
            return false;
    }
    return min==0;
}

int main()
{

}