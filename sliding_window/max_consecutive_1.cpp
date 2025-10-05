#include<bits/stdc++.h>
using namespace std;


/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/
int maxConsecutiveOnes(vector<int> &nums,int k)
{

    //TC-O(n) + O(n)
    //SC-O(1)

    int n=nums.size();
    int cnt=0,left=0,right=0,maxlen=0;
    //BETTER
    while(right<n)
    {
        if(nums[right]==0)
            cnt++;
        while(cnt>k)
        {
            if(nums[left]==0)
                cnt--;
            left++;
        }
        if(cnt<=k)
            maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;


    //BETTER
    cnt=left=right=maxlen=0;
    while(right<n)
    {
        if(cnt==k && nums[right]==0)
        {
            maxlen=max(maxlen,right-left);
            if(nums[left]==0)
                cnt--;
            left++;
            continue;
        }
        if(nums[right]==0)
        {
            cnt++;
        }
        right++;
    }
    maxlen=max(maxlen,right-left);
    return maxlen;



    //OPTIMAL
    //TC-O(n)
    //SC-O(1)
    cnt=left=right=maxlen=0;
    while(right<n)
    {
        if(nums[right]==0)
            cnt++;
        if(cnt>k)
        {
            if(nums[left]==0)
                cnt--;
            left++;
        }
        if(cnt<=k)
            maxlen=max(maxlen,right-left+1);
        right++;
    }
}
int main()
{

}