#include<bits/stdc++.h>
using namespace std;

/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.*/


string removeKDigits(string num,int k)
{
    //TC-O(3n)+O(k)
    //SC-O(2n)
    int n=num.size();
    string ans="";
    if(k==n)
        return "0";
    int i=0;
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && num[i]<st.top() && k>0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k>0)//for cases like [1,2,3,4,5,6]
    {
        st.pop();
        k--;
    }
    if(st.empty())
        return "0";
    while(!st.empty())//converting to string
    {
        ans+=st.top();
        st.pop();
    }
    while(ans.back()=='0')//removing leading zeroes
    {
        ans.pop_back();
        if(ans.size()==0)
            return "0";
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{

}