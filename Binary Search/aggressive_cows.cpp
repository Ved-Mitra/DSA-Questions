#include<bits/stdc++.h>
using namespace std;

/*
Q. place cows in array at stall such that min distance between any cow is maximised
*/
bool place_cows(vector<int>& cows,int cow,int distance)
{
    int last=cows[0];
    int count_Cows=1;
    int n=cows.size();
    for(int i=1;i<n;i++)
    {
        if(cows[i]-last>=distance)
        {
            last=cows[i];
            count_Cows++;
        }
        if(count_Cows>=cow)
            return true;
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter the size of numsay: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the numsay: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];

    cout << " Enter the cows: ";
    int k;
    cin >> k;

    if(n<k)
    {
        cout << " not possible" << endl;
        return 0;
    }
    sort(nums.begin(),nums.end());
    int low=1,high=nums[n-1]-nums[0];
    int ans=1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(place_cows(nums,k,mid))
        {
            ans=mid;
            low=mid+1;
        }
        else
            high=mid-1;
    }
    cout << ans << endl;
    return 0;
}