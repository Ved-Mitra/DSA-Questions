#include <bits/stdc++.h>
using namespace std;

// to understand this question fully first review question sum_of_subarray.cpp

/*You are given an integer array arr[], the task is to find the maximum of minimum values for every window size k where 1≤ k ≤ arr.size().

For each window size k, consider all contiguous subarrays of length k, determine the minimum element in each subarray, and then take the maximum among all these minimums.

Return the results as an array, where the element at index i represents the answer for window size i+1.*/

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


// Some window sizes might not have been filled directly;
// a larger window's min will always be <= a smaller window's min.
vector<int> maxOfMins(vector<int>& arr) {
    //  code here
    int n=arr.size();
    vector<int> ans(n+1);
    vector<int> pse=PSE(arr),nse=NSE(arr);
    for(int i=0;i<n;i++)
    {
        int pse_i=pse[i];
        int nse_i=nse[i];
        int len=nse_i-pse_i-1;
        ans[len]=max(ans[len],arr[i]);
    }

    
    for(int i=n-1;i>=1;i--)
        ans[i]=max(ans[i],ans[i+1]);
    return vector<int> (ans.begin()+1,ans.end());
}
