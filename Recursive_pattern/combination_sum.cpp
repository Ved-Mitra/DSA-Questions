#include<bits/stdc++.h>
using namespace std;

/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.*/
void generateCombination(vector<vector<int>> &ans,vector<int> &candidates,vector<int> &arr,int k,int index,int sum)
{
    if(index==candidates.size())
    {
        if(sum==k)
            ans.push_back(arr);
        return;
    }
    if(sum>k)
        return;
    if(sum==k)
    {
        ans.push_back(arr);
        return;
    }
    arr.push_back(candidates[index]);
    generateCombination(ans,candidates,arr,k,index,sum+candidates[index]);
    arr.pop_back();
    generateCombination(ans,candidates,arr,k,index+1,sum);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    int k;
    cin >> k;
    vector<vector<int>> ans;
    vector<int> arr;
    generateCombination(ans,nums,arr,k,0,0);
}