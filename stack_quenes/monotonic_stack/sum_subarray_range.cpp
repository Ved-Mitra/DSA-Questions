#include<bits/stdc++.h>
using namespace std;

/*You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.*/

vector<int> PGE(vector<int> &nums)
{
    //previous greater element
    int n=nums.size();
    int i=0;
    stack<int> st;
    vector<int> ans(n,-1);
    while(i<n)
    {
        while(!st.empty() && nums[i]>nums[st.top()])
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
vector<int> NGE(vector<int> &nums)
{
    int n=nums.size();
    int i=n-1;
    stack<int> st;
    vector<int> ans(n,n);
    while(i>=0)
    {
        while(!st.empty() && nums[i]>=nums[st.top()])
        {
            st.pop();
        }
        if(!st.empty())
            ans[i]=st.top();
        st.push(i);
        i--;
    }
    return ans;
}
long long sumMax(vector<int> &nums)
{
    int n=nums.size();
    vector<int> pge=PGE(nums);
    vector<int> nge=NGE(nums);
    long long total=0;
    for(int i=0;i<n;i++)
    {
        int left=i-pge[i];
        int right=nge[i]-i;
        long long cnt=(left*right);
        total=(total+cnt*nums[i]);
    }
    return total;
}
vector<int> PSE(vector<int> &nums)
{
    //here we have taken previuos smaller and equal element
    int n=nums.size();
    vector<int> ans(n,-1);
    stack<int> st;
    int i=0;
    while(i<n)
    {
        while(!st.empty() && nums[i]<=nums[st.top()])
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
        while(!st.empty() && nums[i]<nums[st.top()])
            st.pop();
        if(!st.empty())
            ans[i]=st.top();
        st.push(i);
        i--;
    }
    return ans;
}
long long sumMin(vector<int> &nums)
{
    int n=nums.size();
    vector<int> pse,nse;
    //pse--previous smaller element
    //nse--next smaller element
    pse=PSE(nums);
    nse=NSE(nums);
    long long total=0;
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        long long cnt=(left*right);
        total = (total + cnt*nums[i]); 
    }
    return total;
}
long long subArrayRanges(vector<int>& nums) {
    return sumMax(nums)-sumMin(nums);
}

int main()
{
    
}