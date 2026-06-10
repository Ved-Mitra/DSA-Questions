#include <bits/stdc++.h>
using namespace std;


//If the array never changes, a Sparse Table is the best choice. It provides \(O(N \log N)\) preprocessing time and a blazing-fast O(1) query time by storing minimums of ranges that have lengths of powers of 2

//Create a 2D array st[N][K] where N is the array size and k= floor(log2(n)) + 1 . An entry at st[i][j] will store the minimum value in the subarray starting at index i with length 2^j).

//Fill in the intervals of length 2⁰ = 1. This is simply a direct copy of your input array: st[i][0]=arr[i]

//st[i][j]=min(st[i][j-1],st[i+2^(j-1)][j-1])

//RMQ(l,r) = min(st[l][j],srt[r-2^j +1][j])       j=floor(log2(r-l+1))




//LEETCODE 3691
/*You are given an integer array nums of length n and an integer k.

You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.

The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value you can achieve.*/


vector<vector<int>> buildRMQ(vector<int> &arr,int(*comp)(int,int))
{
    int n=arr.size();
    int w=floor(log2(n)) +1;
    vector<vector<int>> rmq(n,vector<int>(w,0));
    for(int i=0;i<n;i++)
        rmq[i][0]=arr[i];
    
    for (int j = 1; j < w; j++) 
    {
        for (int i = 0; i + (1 << j) <= n; i++) 
        {
            rmq[i][j] = comp(rmq[i][j-1], rmq[i + (1 << (j - 1))][j-1]);
        }
    }
    return rmq;
}
int subArrayVal(vector<vector<int>> &maxRMQ,vector<vector<int>> &minRMQ,int l,int r)
{
    int w=r-l+1;
    int j=floor(log2(w));
    int maxVal=max(maxRMQ[l][j],maxRMQ[r-(1<<j)+1][j]);
    int minVal=min(minRMQ[l][j],minRMQ[r-(1<<j)+1][j]);
    return maxVal-minVal;
}
long long maxTotalValue(vector<int>& nums, int k) {
    int n=nums.size();
    vector<vector<int>>maxRMQ=buildRMQ(nums,[] (int a,int b) {return std::max(a,b);});
    vector<vector<int>>minRMQ=buildRMQ(nums,[] (int a,int b) {return std::min(a,b);});
    priority_queue<tuple<int,int,int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push({subArrayVal(maxRMQ,minRMQ,i,n-1),i,n-1});
    }
    int cnt=0;
    long long totVal=0;
    while(cnt<k)
    {
        auto [val,l,r]=pq.top();
        pq.pop();
        totVal+=val;
        if(r>l)
        {
            pq.push({subArrayVal(maxRMQ,minRMQ,l,r-1),l,r-1});
        }
        cnt++;
    }

    return totVal;
}


int main()
{

}