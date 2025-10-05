#include<bits/stdc++.h>
using namespace std;

/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array*/
int binarySubarraySum(vector<int> &nums,int goal)
{
    //BRUTE
    //TC-O(N)
    //SC-O(N)
    int n=nums.size();
    int cnt=0,sum=0,right=0;
    map<int,int> preSum;
    preSum[0]=1;
    while(right<n)
    {
        sum+=nums[right];
        int rem=sum-goal;
        cnt+=preSum[rem];
        preSum[sum]++;
        right++;
    }

    //OPTIMAL
    //TC-O(N)+O(N) *2
    //SC-O(1)
    return func_optimal(nums,goal)-func_optimal(nums,goal-1);
}
int func_optimal(vector<int> &nums,int goal)
{
    if(goal<0)
        return 0;
    int n=nums.size();
    int cnt=0,sum=0;
    int r=0,l=0;
    while(r<n)
    {
        sum+=nums[r];
        while(sum>goal)
        {
            sum-=nums[l];
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}

int main()
{

}