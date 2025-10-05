#include<bits/stdc++.h>
using namespace std;

/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination*/
void generateCombination(vector<vector<int>> &ans,vector<int> &candidates,vector<int> &arr,int k,int index)
{
    //TC-O(2^n * k)
    //SC-O(k*x)  x-->number of combination
    if(k==0)
    {
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<candidates.size();i++)
    {
        if(i>index && candidates[i]==candidates[i-1])
            continue;
        if(candidates[i]>k)
            break;
        arr.push_back(candidates[i]);
        generateCombination(ans,candidates,arr,k-candidates[i],i+1);
        arr.pop_back();
    }
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
    generateCombination(ans,nums,arr,k,0);
}