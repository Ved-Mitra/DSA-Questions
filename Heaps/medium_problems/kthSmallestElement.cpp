#include <bits/stdc++.h>
using namespace std;



int kTHSmallestElement(vector<int> &nums,int k)
{
    int n=nums.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        if(pq.size()<=k || pq.top()<nums[i])
            pq.push(nums[i]);
        if(pq.size()>k)
            pq.pop();
    }
    return pq.top();
}

int main()
{
    
}