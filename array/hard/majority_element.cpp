#include<bits/stdc++.h>
using namespace std;

/*
Q. return the array of elements with occurence n>3 
*/

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int nums[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];

    vector<int> ans;//can have at max 2 elements

    //BRUTE
    //TC-O(N^2)
    //SC-O(1)
    for(int i=0;i<n;i++)
    {
        if(ans.size()==0 || ans[0]!=nums[i])
        {
            int count=0;
            for(int j=0;j<n;j++)
                if(nums[j]==nums[i])
                    count++;
            if(count>n/3)
                ans.push_back(nums[i]);
        }
        if(ans.size()==2)
            break;
    }
    for(auto it:ans)
        cout << it;
    cout <<endl;
    ans.clear();


    //BETTER
    //hashing
    //TC-O(n*log n)
    //SC-O(N)
    map<int,int> mpp;
    int minn=floor(n/3)+1;
    for(int i=0;i<n;i++)
    {
        mpp[nums[i]]++;
        if(mpp[nums[i]]==minn)
            ans.push_back(nums[i]);
        if(ans.size()==2)
            break;
    }
    for(auto it:ans)
        cout << it;
    cout <<endl;
    ans.clear();

    //OPTIMAL
    //TC-O(N)
    //SC-O(1)
    int cnt1=0,cnt2=0,element1=INT_MIN,element2=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && nums[i]!=element2)
        {
            cnt1=1;
            element1=nums[i];
        }
        else if(cnt2==0 && nums[i]!=element1)
        {
            cnt2=1;
            element2=nums[i];
        }
        else if(element1==nums[i])
            cnt1++;
        else if(element2==nums[i])
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(element1==nums[i])
            cnt1++;
        else if(element2==nums[i])
            cnt2++;
    }
    if(cnt1>=minn)
        ans.push_back(element1);
    if(cnt2>=minn)
        ans.push_back(element2);
    for(auto it:ans)
        cout << it;
    cout <<endl;

    return 0;
}