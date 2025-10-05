#include<bits/stdc++.h>
using namespace std;


/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.*/

int subarrayWithKDistinctIntegers(vector<int> &nums,int k)
{
    int n=nums.size();

    //BRUTE
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        map<int,int> mpp;
        for(int j=i;j<n;j++)
        {
            mpp[nums[j]]++;
            if(mpp.size()==k)
                cnt++;
            else if(mpp.size()>k)
                break;
        }
    }
    return cnt;


    //OPTIMAL
    return solve_optimal(nums,k)-solve_optimal(nums,k-1);
}

int solve_optimal(vector<int> &nums,int k)
{
    //solving for atmost k different integers
    if(k<0)
        return 0;
    int n=nums.size();
    unordered_map<int,int> hash;
    int l=0,r=0,cnt=0,ans=0;
    while(r<n)
    {
        hash[nums[r]]++;
        if(hash[nums[r]]==1)
            cnt++;
        while(cnt>k)
        {
            hash[nums[l]]--;
            if(hash[nums[l]]==0)
                cnt--;
            l++;
        }
        ans+=(r-l+1);
        r++;
    }
    return ans;
}


int main()
{

}