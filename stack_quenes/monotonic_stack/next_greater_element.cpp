#include<bits/stdc++.h>
using namespace std;

//WHEN WE START TO STORE ELEMENT IN A SPECIFIC ORDER IN STACK, IT IS CALLED MONOTONIC STACK


/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.*/

vector<int> nextGreaterElement_1(vector<int> &nums1,vector<int> &nums2)
{
    int n=nums1.size();
    int m=nums2.size();
    vector<int> ans(n,-1);
    if(m==0)
        return ans;
    if(n==0)
        return {};
    unordered_map<int,int> hash;
    stack<int> st;
    for(int i=m-1;i>=0;i--)
    {
        while(!st.empty() && nums2[i]>=st.top())
        {
            st.pop();
        }
        if(st.empty())
            hash[nums2[i]]=-1;
        else
            hash[nums2[i]]=st.top();
        st.push(nums2[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(hash.find(nums1[i])!=hash.end())
            ans[i]=hash[nums1[i]];
    }
    return ans;
}




/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.*/
vector<int> nextGreaterElement_2(vector<int>& nums) 
{
    int n=nums.size();
    vector<int> ans(n,-1);
    if(n==0)
        return {};
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums[i]>=st.top())
        {
            st.pop();
        }
        if(st.empty())
            ans[i]=-1;
        else
            ans[i]=st.top();
        st.push(nums[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums[i]>=st.top())
        {
            st.pop();
        }
        if(st.empty())
            ans[i]=-1;
        else
            ans[i]=st.top();
        st.push(nums[i]);
    }
    return ans;
}

int main()
{
    
}