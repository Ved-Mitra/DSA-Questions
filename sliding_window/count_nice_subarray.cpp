#include<bits/stdc++.h>
using namespace std;

/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.*/
int func_optimal(vector<int> &nums,int goal)
{
    if(goal<0)
        return 0;
    int n=nums.size();
    int cnt=0,sum=0;
    int r=0,l=0;
    while(r<n)
    {
        sum+=(nums[r]&1);
        while(sum>goal)
        {
            sum-=(nums[l]&1);
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
int countNiceSubarray(vector<int> &nums,int k)
{
    //same as binary subarray sum just do moduli to eah element of nums
    return func_optimal(nums,k)-func_optimal(nums,k-1);

}

int main()
{

}