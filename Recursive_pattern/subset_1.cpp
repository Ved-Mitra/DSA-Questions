#include<bits/stdc++.h>
using namespace std;

void subset_1(vector<int> &ans,vector<int> &arr,vector<int> &nums,int index,int sum)
{
    //given arr of N integers , print sum of all subsets in it in increasing order
    if(nums.size()==index)
    {
        int summ=accumulate(arr.begin(),arr.end(),0);
        ans.push_back(summ);
        return;
    }
    arr.push_back(nums[index]);
    subset_1(ans,arr,nums,index+1,sum+nums[index]);
    arr.pop_back();
    subset_1(ans,arr,nums,index+1,sum+nums[index]);    
}

int main()
{
    vector<int> ans,arr,nums;

    subset_1(ans,arr,nums,0,0);
    sort(ans.begin(),ans.end());
    return 0;
}