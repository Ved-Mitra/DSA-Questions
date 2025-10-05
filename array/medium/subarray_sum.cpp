#include<bits/stdc++.h>
using namespace std;

/*
Q. return the number of subarray with sum k
*/

int main()
{
    int n;
    cout << "Enter the size of array: " ;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Enter the sum: ";
    int k;
    cin >> k;
    //OPTIMAL(PREFIX SUM)
    map<int,int> mpp;
    mpp[0]=1;
    int preSum=0,count=0;
    for(int i=0;i<n;i++)
    {
        preSum+=arr[i];
        int rem=preSum-k;
        count+=mpp[rem];
        mpp[preSum]+=1;
    }
    cout << count << endl;
}