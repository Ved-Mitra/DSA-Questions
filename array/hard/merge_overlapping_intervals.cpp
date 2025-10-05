#include<bits/stdc++.h>
using namespace std;

/*
Q. return the array with all overlapping subintervals merged
*/

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int nums[n][2];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            cin >> nums[i][j];
    
    vector<vector<int>> ans;
    //BRUTE
    //TC-O(N log n) + O(N)
    //SC-O(1)
    sort(nums,nums+n);
    for(int i=0;i<n;i++)
    {
        int start=nums[i][0];
        int end=nums[i][1];
        if(!ans.empty() && end<=ans.back()[1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(nums[j][0]<=end)
            {
                end=max(end,nums[j][1]);
            }
            else
                break;
        }
        ans.push_back({start,end});
    }
    for(auto it1:ans)
    {
        for(auto it2:it1)
            cout<<it2<<",";
        cout<< endl;
    }
    ans.clear();


    //OPTIMAL
    //APPROACH-1
    sort(nums,nums+n);
    int start=nums[0][0];
    int end=nums[0][1];
    for(int i=0;i<n;i++)
    {
        if(end>=nums[i][0])
        {
            end=max(end,nums[i][1]);
        }
        else
        {
            ans.push_back({start,end});
            start=nums[i][0];
            end=nums[i][1];
        }
    }
    for(auto it1:ans)
    {
        for(auto it2:it1)
            cout<<it2<<",";
        cout<< endl;
    }
    ans.clear();

    //APPROACH-2
    //TC-O(N logn)
    //SC-O(1)
    sort(nums,nums+n);
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || nums[i][0]>ans.back()[1])
        {
            ans.push_back({nums[i][0],nums[i][1]});
        }
        else
        {
            ans.back()[1]=max(ans.back()[1],nums[i][1]);
        }
    }
    return 0;
}