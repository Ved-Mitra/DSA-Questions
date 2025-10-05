#include<bits/stdc++.h>
using namespace std;

/*You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].*/

int jump(vector<int> &nums)
{
    int n=nums.size();

    //OPTIMAL-ME
    //TC-O(n)
    //SC-O(1)
    int cnt=1;
    int maxIndex=nums[0];
    if(n==1)
        return 0;
    int maxx=nums[0];
    for(int i=0;i<n;i++)
    {
        maxx=max(maxx,i+nums[i]);
        if(i==maxIndex)
        {
            cnt++;
            maxIndex=max(maxIndex,max(i+nums[i],maxx));
        }
        if(maxIndex>=n-1)
            return cnt;
    }
    return cnt;

    //OPTIMAL-STRIVER
    //TC-O(n)
    //SC-O(1)
    int jumps=0,l=0,r=0;
    while(r<n-1)
    {
        int farthest=0;
        for(int index=l;index<n;index++)
        {
            farthest=max(index+nums[index],farthest);
        }
        l=r+1;
        jumps++;
        r=farthest;
    }
    return jumps;
}

int main()
{

}