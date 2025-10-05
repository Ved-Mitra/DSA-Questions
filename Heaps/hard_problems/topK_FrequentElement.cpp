#include <bits/stdc++.h>
using namespace std;

/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.*/

vector<int> topKFrequent(vector<int> &nums,int k)
{
    int n=nums.size();
    unordered_map<int,int> hash;
    for(int i=0;i<n;i++)
        hash[nums[i]]++;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto &x:hash)
    {
        if(pq.size()<k || pq.top().first<x.second)
            pq.push({x.second,x.first});
        if(pq.size()>k)
            pq.pop();
    }
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}



int main()
{

}