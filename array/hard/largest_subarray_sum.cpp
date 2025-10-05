#include<bits/stdc++.h>
using namespace std;

/*
Q. return the largest subarray with sum target
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
    int target;
    cout << "Enter the sum: " ;
    cin >> target;

    vector<int> ans;
    int start=0,end=0;
    int length=0;
    long long sum=0;
    map<long long,int> hash;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(sum==target)
        {
            if(length<i+1)
            {
                length=i+1;
                start=0;
                end=i;
            }
        }
        long long rem=sum-target;
        if(hash.find(rem)!=hash.end())
        {
            int len=i-hash[rem];
            if(length<len)
            {
                length=i+1;
                start=hash[rem]+1;
                end=i;
            }
        }
        if(hash.find(rem)==hash.end())
        {
            hash[rem]=i;
        }
    }
    for(int i=start;i<=end;i++)
        ans.push_back(nums[i]);
    for(auto it:ans)
        cout << it << ",";
    cout << endl;

    return 0;
}