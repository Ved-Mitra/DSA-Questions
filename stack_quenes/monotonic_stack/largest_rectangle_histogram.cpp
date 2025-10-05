#include<bits/stdc++.h>
using namespace std;

/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.*/

vector<int> NSE(vector<int> &nums)
{
    int n=nums.size();
    int i=n-1;
    stack<int> st;
    vector<int> ans(n,n);
    while(i>=0)
    {
        while(!st.empty() && nums[i]<=nums[st.top()])
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
vector<int> PSE(vector<int> &nums)
{
    int n=nums.size();
    int i=0;
    stack<int> st;
    vector<int> ans(n,-1);
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
int largestRectangleArea(vector<int> &heights)
{
    int n=heights.size();
    int maxsum=0;

    //BRUTE
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j>=0;j--)//backwards
        {
            if(heights[j]>=heights[i])
                sum+=heights[i];
        }
        for(int j=i+1;j<n;j++)//forwards
        {
            if(heights[j]>=heights[i])
                sum+=heights[i];
        }
        maxsum=max(maxsum,sum);
    }
    return maxsum;

    //BETTER
    maxsum=0;
    vector<int> pse=PSE(heights);
    vector<int> nse=NSE(heights);
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        maxsum=max(maxsum,(left+right-1)*heights[i]);
    }
    return maxsum;


    //OPTIMAL
    //TC-O(2n)
    //SC-O(n)
    int maxarea=0;
    stack<int> st;
    for(int i=0;i<n;i++)//O(n)
    {
        while(!st.empty() && heights[st.top()]>heights[i])
        {
            int element=st.top();
            st.pop();
            int nse=i;
            int pse=st.empty()?-1:st.top();
            maxarea=max(heights[element]*(nse-pse-1),maxarea);
        }
        st.push(i);
    }
    while(!st.empty())//O(n)
    {
        int nse=n;
        int element=st.top();
        st.pop();
        int pse=st.empty()?-1:st.top();
        maxarea=max(maxarea,(nse-pse-1)*heights[element]);
    }
    return maxarea;
}


int main()
{

}