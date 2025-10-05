#include<bits/stdc++.h>
using namespace std;


void subset_2(vector<vector<int>> &ans,vector<int> &nums,vector<int> &arr,int index)
{
    ans.push_back(arr);
    for(int i=index;i<nums.size();i++)
    {
        if(i>index && nums[i-1]==nums[i])
            continue;
        arr.push_back(nums[i]);
        subset_2(ans,nums,arr,i+1);
        arr.pop_back();
    }
}
int main()
{

}