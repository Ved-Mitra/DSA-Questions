#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of numsay: " ;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the numsay: " << endl;
    for(int i=0;i<n;i++)
        cin >> nums[i];

    cout << " Enter the number: ";
    int k;
    cin >> k;

    if(k<nums[0])
        return k;
    if(k>nums[n-1])
        return n+k;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int missing=nums[mid]-(mid+1);
        if(k<=missing)
            high=mid-1;
        else if(k>missing)
            low=mid+1;
    }
    cout <<  (high+1)+k << endl;

}