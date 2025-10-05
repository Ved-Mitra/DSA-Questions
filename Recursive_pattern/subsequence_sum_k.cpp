#include<bits/stdc++.h>
using namespace std;


void subsequenceSumK(vector<vector<int>> &ans,vector<int> &nums,vector<int> &arr,int index,int sum,int k)
{
    if(index==nums.size())
    {
        if(sum==k)
            ans.push_back(arr);
        return;
    }

    arr.push_back(nums[index]);
    subsequenceSumK(ans,nums,arr,index+1,sum+nums[index],k);
    arr.pop_back();
    subsequenceSumK(ans,nums,arr,index+1,sum,k);
    return;
}

bool subsequenceSumK_onlyOneAnswer(vector<vector<int>> &ans,vector<int> &nums,vector<int> &arr,int index,int sum,int k)
{
    if(index==nums.size())
    {
        if(sum==k)
        {
            ans.push_back(arr);
            return true;
        }
        return false;
    }

    arr.push_back(nums[index]);
    if(subsequenceSumK_onlyOneAnswer(ans,nums,arr,index+1,sum+nums[index],k))
        return true;
    arr.pop_back();
    if(subsequenceSumK_onlyOneAnswer(ans,nums,arr,index+1,sum,k))
        return true;
    return false;
}

int subsequenceSumK_Count(vector<vector<int>> &ans,vector<int> &nums,int index,int sum,int k)
{
    //works with only positives
    if(sum>k)
        return 0;
    if(index==nums.size())
    {
        if(sum==k)
        {
            return 1;
        }
        return 0;
    }

    int l= subsequenceSumK_Count(ans,nums,index+1,sum+nums[index],k);

    int r= subsequenceSumK_Count(ans,nums,index+1,sum,k);
    return l+r;
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
}
