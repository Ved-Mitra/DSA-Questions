#include<bits/stdc++.h>
using namespace std;

/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.*/

vector<int> PSE(vector<int> &nums)
{
    //here we have taken previuos smaller and equal element
    int n=nums.size();
    vector<int> ans(n,-1);
    stack<int> st;
    int i=0;
    while(i<n)
    {
        while(!st.empty() && nums[i]<nums[st.top()])
        {
            st.pop();
        }
        if(!st.empty())
            ans[i]=st.top();
        st.push(i);
        i++;
    }
    return ans;
}
vector<int> NSE(vector<int> &nums)
{
    int n=nums.size();
    int i=n-1;
    stack<int> st;
    vector<int> ans(n,n);
    while(i>=0)
    {
        while(!st.empty() && nums[i]<=nums[st.top()])
            st.pop();
        if(!st.empty())
            ans[i]=st.top();
        st.push(i);
        i--;
    }
    return ans;
}
int sumSubarrayMin(vector<int> &arr)
{
    int n=arr.size();
    int sum=0;
    int mod=1e9 + 7;

    //BRUTE
    for(int i=0;i<n;i++)
    {
        int mini=arr[i];
        for(int j=i;j<n;j++)
        {
            mini=min(mini,arr[j]);
            sum=(sum+mini)%mod;
        }
    }
    return sum;


    //OPTIMAL
    //TC-O(5n)
    //SC-O(5n)
    vector<int> pse,nse;
    //pse--previous smaller element
    //nse--next smaller element
    pse=PSE(arr);
    nse=NSE(arr);
    int total=0;
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        long long cnt=(left*right)%mod;
        total = (total + cnt*arr[i])%mod; 
    }
    return total;
}

int main()
{

}