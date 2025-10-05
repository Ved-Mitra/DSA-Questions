#include<bits/stdc++.h>
using namespace std;



void printAllSubsequence(vector<vector<int>> &ans,vector<int> &nums,vector<int> &arr,int index)
{
    //TC-O(2^n * n)
    //SC-O(n) excluding for thr memory of ans
    if(index>=nums.size())
    {
        ans.push_back(arr);
        return;
    }
    //take element at nums[index]
    arr.push_back(nums[index]);
    printAllSubsequence(ans,nums,arr,index+1);

    //don't take element at nums[index]
    arr.pop_back();
    printAllSubsequence(ans,nums,arr,index+1);
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    vector<vector<int>> ans;

}
