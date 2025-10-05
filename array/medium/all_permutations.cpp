#include<bits/stdc++.h>
using namespace std;

/*
Q. give all permutation of given array in any order
*/

void approach2(int index,vector<int>&nums,vector<vector<int>> &ans)
{
    if(index==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++)
    {
        swap(nums[index],nums[i]);
        approach2(index+1,nums,ans);
        swap(nums[index],nums[i]);
    }
}
void approach1(vector<vector<int>> &ans, vector<int>&ds,vector<int>&nums,int freq[])
{
    //TC-O(n! * n)
    //SC-O(n)
    if(ds.size()==nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i]=1;
            approach1(ans,ds,nums,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    vector<int> arr(n,0);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<vector<int>> ans;
    vector<int>ds;
    int freq[n]={0};
    approach1(ans,ds,arr,freq);   
    for(auto it1:ans)
    {
        for(auto it2:it1)
            cout << it2;
    }
    ans.clear();
    cout<<endl;
    approach2(0,arr,ans);
    for(auto it1:ans)
    {
        for(auto it2:it1)
            cout << it2;
    }
}